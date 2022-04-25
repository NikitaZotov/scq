grammar scq;

options
{
  language = Cpp;
}

@header
{
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"
}

program
	locals
	[
	using Procedures = std::unordered_set<std::string>,
	Procedures * procs = new Procedures(),

	using ObjectsDefinitions = std::vector<std::array<std::string, 4>>,
    ObjectsDefinitions * objDefs = new ObjectsDefinitions(),

	using Objects = std::unordered_map<std::string, std::string>,
    Objects * objects = new Objects(),

	using ProcedureDefinitions
		= std::unordered_map<
			std::string,
			std::pair<
				std::vector<std::pair<std::string, std::string>> *,
				std::pair<ProgramContext::ObjectsDefinitions *, ProgramContext::Objects *>
			>
		>,
	ProcedureDefinitions * procDefs = new ProcedureDefinitions(),
	]
	: procDeclaration[$procs]* procDefinition[$procs, $procDefs]* block[$procDefs, nullptr, $objDefs, $objects]
	;
	catch[utils::ScException const & e] {SC_LOG_ERROR("Parse error occurred: " + std::string(e.Message()));}

procDeclaration
	[ProgramContext::Procedures * procs]
	: PROCEDURE_TYPE EDGE_OP NAME
	{
	if ($procs->find($NAME.text) != $procs->end()) {
	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + $NAME.text + "\" is declared.");
	}
	else {
	  $procs->insert($NAME.text);
	  SC_LOG_DEBUG("Declare \"" + $NAME.text + "\" procedure");
    }
	}
	(COMMA NAME
	{
    if ($procs->find($NAME.text) != $procs->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + $NAME.text + "\" is declared.");
    }
    else {
      $procs->insert($NAME.text);
      SC_LOG_DEBUG("Declare \"" + $NAME.text + "\" procedure");
    }
    }
	)*
	SEMICOLON
	;

procDefinition
	[ProgramContext::Procedures * procs, ProgramContext::ProcedureDefinitions * procDefs]
	locals
    [
    using ProcedureParams = std::vector<std::pair<std::string, std::string>>,
    ProcedureParams * params = new ProcedureParams(),
    ProgramContext::ObjectsDefinitions * objDefs = new ProgramContext::ObjectsDefinitions(),
    ProgramContext::Objects * objects = new ProgramContext::Objects(),
    ]
 	: (PROCEDURE_TYPE EDGE_OP)? NAME
 	{
    if ($procs->find($NAME.text) == $procs->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + $NAME.text + "\" isn't declared.");
    }
    }
 	ASSIGN_OP procParams[$params] COMMA block[$procDefs, $params, $objDefs, $objects]
 	{
 	$procDefs->insert({ $NAME.text, { $params, { $objDefs, $objects } } });
    SC_LOG_DEBUG("Define \"" + $NAME.text + "\" procedure");
 	}
 	SEMICOLON
 	;

procParams[ProcDefinitionContext::ProcedureParams * params]
	: LEFT_CURL_BRACKET (OBJECT_TYPE EDGE_OP NAME
	{
	if (std::find_if($params->begin(), $params->end(), [&](auto & item) -> bool { item.first == $NAME.text; })
	  != $params->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param \"" + $NAME.text + "\" is repeated.");
    }
    else {
      $params->push_back({ $NAME.text, $OBJECT_TYPE.text });
      SC_LOG_DEBUG("Define \"" + $NAME.text + "\" param");
    }
	}
	)* (COMMA (OBJECT_TYPE EDGE_OP)* NAME
	{
    if (std::find_if($params->begin(), $params->end(), [&](auto & item) -> bool { item.first == $NAME.text; })
      != $params->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param \"" + $NAME.text + "\" is repeated.");
    }
    else {
      $params->push_back({ $NAME.text, $OBJECT_TYPE.text });
      SC_LOG_DEBUG("Define \"" + $NAME.text + "\" param");
    }
    }
	)* RIGHT_CURL_BRACKET
	;

block
	[
	ProgramContext::ProcedureDefinitions * procDefs,
	ProcDefinitionContext::ProcedureParams * params,
	ProgramContext::ObjectsDefinitions * objDefs,
	ProgramContext::Objects * objects
	]
    @init
    {
    if (params != nullptr) {
      std::for_each(params->begin(), params->end(), [&](const auto & item) {
        $objects->insert(item);
      });
    }
    }
    @after
    {
    for (auto const & item : *$objDefs) {
      std::cout << "<" << item.at(0)
      		<< ">  <" << item.at(1)
      		<< ">  <" << item.at(2)
      		<< ">  <" << item.at(3)
      		<< ">" << std::endl;
	}
    }
    : (objectDeclaration[$objects, $procDefs]
    | objectDefinition[$objects, $objDefs, $procDefs]
    | operation[$objects, $objDefs, $procDefs])*
    ;

objectDeclaration
	[ProgramContext::Objects * objects, ProgramContext::ProcedureDefinitions * procDefs]
	: OBJECT_TYPE (COMMA (OBJECT_TYPE | (NAME
	{
    if ($objects->find($NAME.text) == $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $NAME.text + "\" isn't declared.");
    }
    }
	)))* EDGE_OP NAME
	{
    if ($objects->find($NAME.text) != $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $NAME.text + "\" is declared.");
    }
    else {
      $objects->insert({ $NAME.text, $OBJECT_TYPE.text });
      SC_LOG_DEBUG("Declare \"" + $NAME.text + "\" object");
    }
    }
    (COMMA NAME
    {
    if ($objects->find($NAME.text) != $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $NAME.text + "\" is declared.");
    }
    else {
      $objects->insert({ $NAME.text, $OBJECT_TYPE.text });
      SC_LOG_DEBUG("Declare \"" + $NAME.text + "\" object");
    }
    }
    )*
	SEMICOLON
	;

objectDefinition
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	ProgramContext::ProcedureDefinitions * procDefs
	]
	locals
	[
	size_t paramNum = 0,
	ProcDefinitionContext::ProcedureParams * funcParams = new ProcDefinitionContext::ProcedureParams(),
	size_t depth = 0,
	]
	: (((OBJECT_TYPE | ((n0=NAME ASSIGN_OP)? n1=NAME
	{
	auto const & it = $procDefs->find($n1.text);
	if (it != $procDefs->end()) {
	  $funcParams = (*procDefs->find($n1.text)).second.first;
	  SC_LOG_DEBUG("Define \"" + $n1.text + "\" function call");
	  $objDefs->push_back({ "call", $n1.text, std::to_string($funcParams->size()), "" });
	}
    }
	)
	| (n1=NAME
	{
	auto const & it = $procDefs->find($n1.text);
	if ($objects->find($n1.text) == $objects->end()) {
	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $n1.text + "\" isn't declared.");
	}
	}
	)) EDGE_OP compositeOperand[$objects, $objDefs, &$paramNum, $funcParams, $depth])
	{
	if ($paramNum > $funcParams->size()) {
	  SC_THROW_EXCEPTION(
	    utils::ExceptionInvalidParams,
	    "Expected " + std::to_string($funcParams->size()) + " params. Gotten " + std::to_string($paramNum) + ".");
	}

	if ($n0 != nullptr)
	{
	  if ($objects->find($n0.text) == $objects->end()) {
		SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $n0.text + "\" isn't declared.");
	  }
	  else {
		SC_LOG_DEBUG("Define \"" + $n0.text + "\" object");
		$objDefs->push_back({ "assign", $n0.text, std::to_string(1), "" });
		$objDefs->push_back({ "param", $n1.text, std::to_string(0), "" });
	  }
	}
	}
	| (((n3=NAME ASSIGN_OP
	{
	if ($n3 != nullptr) {
	  if ($objects->find($n3.text) == $objects->end()) {
		SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $n3.text + "\" isn't declared.");
	  }
	  else {
		SC_LOG_DEBUG("Define \"" + $n3.text + "\" object");
		$objDefs->push_back({ "assign", $n3.text, std::to_string(1), "" });
	  }
	}
	}
	)? assignable[$objects, $objDefs, &$paramNum, $funcParams, $depth])
	| ((n3=NAME ASSIGN_OP)? o1=operation[$objects, $objDefs, $procDefs]
	{
	if ($n3 != nullptr) {
	  if ($objects->find($n3.text) == $objects->end()) {
	    SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $n3.text + "\" isn't declared.");
	  }
	  else {
	    SC_LOG_DEBUG("Define \"" + $n3.text + "\" object");
	    $objDefs->push_back({ "assign", $n3.text, std::to_string(1), "" });
	    $objDefs->push_back({ "param", $o1.name, std::to_string(0), "" });
	  }
	}
	})))
	SEMICOLON
	;

operation
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	ProgramContext::ProcedureDefinitions * procDefs,
	]
	returns [std::string name]
	locals
	[
	size_t paramNum = 0,
	std::vector<std::vector<std::string>> paramTypes,
	size_t depth = 0,
    ]
 	: ((o1=setOperation[&$paramTypes]
	{
	SC_LOG_DEBUG("Define \"" + $setOperation.text + "\" operation");
	$objDefs->push_back({ "call", $setOperation.text, "", "" });

	$name = $o1.text;
	}
 	) EDGE_OP ((LEFT_CURL_BRACKET
 	{
	  $objDefs->push_back({ "param", "()", std::to_string($depth), "" });
	}
 	operationOperand[$objects, $objDefs, &$paramNum, &$paramTypes, $depth + 1]
 	(COMMA operationOperand[$objects, $objDefs, &$paramNum, &$paramTypes, $depth + 1])* RIGHT_CURL_BRACKET)
 	| templateCommand[$objects, $objDefs, $procDefs])
 	{
    if ($paramNum > $paramTypes.size()) {
      SC_THROW_EXCEPTION(
        utils::ExceptionInvalidParams,
    	"Expected " + std::to_string($paramTypes.size()) + " params. Gotten " + std::to_string($paramNum) + ".");
    }
    })
	| (IF_OP EDGE_OP
	{
	  SC_LOG_DEBUG("Define \"" + $IF_OP.text + "\" operation");
	  $objDefs->push_back({ "call_if", "search", std::to_string(1), "" });
	}
	templateExpression[$objects, $objDefs, $procDefs]
	COMMA (operation[$objects, $objDefs, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs])
	(COMMA (operation[$objects, $objDefs, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs])
	)*
	(COMMA ELSE_OP EDGE_OP
	{
	  SC_LOG_DEBUG("Define \"" + $IF_OP.text + "\" operation");
	  $objDefs->push_back({ "call_if", "search", std::to_string(1), "" });
	}
	templateExpression[$objects, $objDefs, $procDefs]
	COMMA (operation[$objects, $objDefs, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs])
	(COMMA (operation[$objects, $objDefs, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs])
	)*
	)*
	{
	  $objDefs->push_back({ "end", $ELSE_OP.text, "", "" });
	}
	'endif'
	)
	;

compositeOperand
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	size_t * paramNum,
	ProcDefinitionContext::ProcedureParams * params,
	size_t depth,
	]
 	: LEFT_CURL_BRACKET
 	{
	  $objDefs->push_back({ "param", "()", std::to_string(depth), "" });
	}
 	operand[$objects, $objDefs, $paramNum, $params, $depth + 1]?
 	(COMMA operand[$objects, $objDefs, $paramNum, $params, $depth + 1])* RIGHT_CURL_BRACKET
 	;

assignable
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	size_t * paramNum,
	ProcDefinitionContext::ProcedureParams * params,
	size_t depth,
	]
 	: (LEFT_CURL_BRACKET
 	{
	  $objDefs->push_back({ "param", "()", std::to_string(depth), "" });
	}
 	operand[$objects, $objDefs, $paramNum, $params, $depth + 1]?
 	(COMMA operand[$objects, $objDefs, $paramNum, $params, $depth + 1])* RIGHT_CURL_BRACKET)
 	| (LEFT_FIGURE_BRACKET
 	{
	  $objDefs->push_back({ "param", "{}", std::to_string(depth), "" });
	}
 	operand[$objects, $objDefs, $paramNum, $params, $depth + 1]?
    (COMMA operand[$objects, $objDefs, $paramNum, $params, $depth + 1])* RIGHT_FIGURE_BRACKET)
 	;

operationOperand
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	size_t * paramNum,
	std::vector<std::vector<std::string>> * params,
	size_t depth,
	]
 	: NAME
 	{
    if ($objects->find($NAME.text) == $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $NAME.text + "\" isn't declared.");
    }

	if (paramNum != nullptr && params != nullptr) {
 	  if (*paramNum < params->size()) {
	    if ($objects->find($NAME.text) == $objects->end()) {
	      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $NAME.text + "\" isn't declared.");
	    }

	    std::vector<std::string> & expectedTypes = $params->at(*$paramNum);
	    std::string & type = (*$objects->find($NAME.text)).second;
	    if (std::find(expectedTypes.begin(), expectedTypes.end(), type) == expectedTypes.end()) {
	      SC_THROW_EXCEPTION(
	        utils::ExceptionInvalidParams,
	        "Unexpected param \"" + $NAME.text + "\" with type \"" + type + "\" in function call." \
	        "Expected param with type \"" + expectedTypes.at(0) + "\".");
	    }
      }
      ++(*$paramNum);
    }
    $objDefs->push_back({ "param", $NAME.text, std::to_string($depth), "" });
    }
	| (STRING
	{
	if (paramNum != nullptr && params != nullptr) {
      if (*paramNum < params->size()) {
    	std::vector<std::string> & expectedTypes = $params->at(*$paramNum);
    	if (std::find(expectedTypes.begin(), expectedTypes.end(), "string") == expectedTypes.end()) {
    	  SC_THROW_EXCEPTION(
    	    utils::ExceptionInvalidParams,
    	    "Unexpected param \"" + $STRING.text + "\" with type \"string\" in function call." \
    	    "Expected param with type \"" + expectedTypes.at(0) + "\".");
    	}
      }
      ++(*$paramNum);
    }
    $objDefs->push_back({ "param", $STRING.text, std::to_string($depth), "" });
    })
    ;

operand
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	size_t * paramNum,
	ProcDefinitionContext::ProcedureParams * params,
	size_t depth,
	]
 	: NAME
 	{
 	if (paramNum != nullptr && params != nullptr) {
 	  if (*paramNum < params->size()) {
	    if ($objects->find($NAME.text) == $objects->end()) {
	      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $NAME.text + " isn't declared.");
	    }

	    std::string & expectedType = $params->at(*$paramNum).second;
	    std::string & type = (*$objects->find($NAME.text)).second;
	    if (expectedType != type) {
	      SC_THROW_EXCEPTION(
	        utils::ExceptionInvalidParams,
	        "Unexpected param \"" + $NAME.text + "\" with type \"" + type + "\" in function call." \
	        "Expected param with type \"" + expectedType + "\".");
	    }
      }
      ++(*$paramNum);
    }

    $objDefs->push_back({ "param", $NAME.text, std::to_string($depth), "" });
	}
	| STRING
	| orientedSet[$objects, $objDefs, $paramNum, $params, $depth]
	| nonOrientedSet[$objects, $objDefs, $paramNum, $params, $depth]
	;

nonOrientedSet
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	size_t * paramNum,
	ProcDefinitionContext::ProcedureParams * params,
	size_t depth,
	]
 	: LEFT_FIGURE_BRACKET
 	{
 	if (paramNum != nullptr && params != nullptr) {
 	  if (*paramNum < params->size()) {
 	    std::string & type = $params->at(*$paramNum).second;
 	    if ($params->at(*$paramNum).second != "set") {
 	      SC_THROW_EXCEPTION(
 	        utils::ExceptionInvalidParams,
 	        "Unexpected param with type \"set\" in function call. Expected param with type \"" + type + "\".");
 	    }
	  }
 	  ++(*$paramNum);
 	}
 	}
 	{
	  $objDefs->push_back({ "param", "{}", std::to_string(depth), "" });
	}
 	operand[$objects, $objDefs, $paramNum, $params, $depth + 1]?
    (COMMA operand[$objects, $objDefs, $paramNum, $params, $depth + 1])*
 	RIGHT_FIGURE_BRACKET
 	;

orientedSet
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	size_t * paramNum,
	ProcDefinitionContext::ProcedureParams * params,
	size_t depth,
	]
	: LEFT_CURL_BRACKET
	{
	if (paramNum != nullptr && params != nullptr) {
	  if (*paramNum < params->size()) {
        std::string & type = $params->at(*$paramNum).second;
        if ($params->at(*$paramNum).second != "tuple") {
          SC_THROW_EXCEPTION(
            utils::ExceptionInvalidParams,
            "Unexpected param with type \"tuple\" in function call. Expected param with type \"" + type + "\".");
        }
      }
	  ++(*$paramNum);
	}
    }
    {
	  $objDefs->push_back({ "param", "()", std::to_string(depth), "" });
	}
	operand[$objects, $objDefs, $paramNum, $params, $depth + 1]?
    (COMMA operand[$objects, $objDefs, $paramNum, $params, $depth + 1])*
	RIGHT_CURL_BRACKET
	;

templateCommand
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	ProgramContext::ProcedureDefinitions * procDefs,
	]
	: templateExpression[$objects, $objDefs, $procDefs] (commandTemplateResult[$objects, $objDefs, $procDefs])?
	;

templateExpression
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	ProgramContext::ProcedureDefinitions * procDefs,
	]
	: LEFT_SQUARE_BRACKET
	commandTemplate[$objects, $objDefs, $procDefs] (COMMA commandTemplate[$objects, $objDefs, $procDefs])*
	RIGHT_SQUARE_BRACKET
	;

commandTemplate
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	ProgramContext::ProcedureDefinitions * procDefs,
	]
	: source=templateParam[$objects, $objDefs, $procDefs] EDGE_OP target=templateParam[$objects, $objDefs, $procDefs]
	{
	$objDefs->push_back({ "param", $source.param, "0", "" });
	$objDefs->push_back({ "param", $target.param, "0", "" });
	}
	;

commandTemplateResult
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	ProgramContext::ProcedureDefinitions * procDefs,
	]
	: AS_OP LEFT_SQUARE_BRACKET
	templateParam[$objects, $objDefs, $procDefs]
	(COMMA templateParam[$objects, $objDefs, $procDefs])*
	RIGHT_SQUARE_BRACKET
	;

templateParam
	[
	ProgramContext::Objects * objects,
	ProgramContext::ObjectsDefinitions * objDefs,
	ProgramContext::ProcedureDefinitions * procDefs,
	]
 	returns [std::string param]
	: (n1=OBJECT_TYPE
	{
    $param = $n1.text;
    }
	)
	| (n1=NAME
	{
	$param = $n1.text;

	if ($n1 != nullptr)
	{
	  auto const & it = $procDefs->find($n1.text);
	  if ($objects->find($n1.text) == $objects->end()) {
	    SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $n1.text + "\" isn't declared.");
	  }
	}
	})
	| ((LEFT_TRIANGLE_BRACKET n2=NAME RIGHT_TRIANGLE_BRACKET)
	{
	$param = "<" + $n2.text + ">";
	objects->insert({ $n2.text, "set" });
	})
	;

setOperation[std::vector<std::vector<std::string>> * paramTypes]
	: 'intersect'
	{
	paramTypes->push_back({ "set" });
	paramTypes->push_back({ "set" });
	}
	| 'complement'
	{
    paramTypes->push_back({ "set" });
    paramTypes->push_back({ "set" });
    }
	| 'unite'
	{
	paramTypes->push_back({ "set" });
	paramTypes->push_back({ "set" });
    }
	| 'remove'
	{
    paramTypes->push_back({ "set", "tuple", "terminal" });
    }
	| 'set_idtf'
	{
	paramTypes->push_back({ "set", "tuple", "terminal" });
    paramTypes->push_back({ "string" });
    }
    | 'resolve_idtf'
	{
	paramTypes->push_back({ "string" });
	}
	| 'dump'
	{
    paramTypes->push_back({ "set", "tuple", "terminal" });
    }
	| 'return'
	{
   	paramTypes->push_back({ "set", "tuple", "terminal" });
   	paramTypes->push_back({ "set", "tuple", "terminal" });
   	paramTypes->push_back({ "set", "tuple", "terminal" });
    paramTypes->push_back({ "set", "tuple", "terminal" });
    paramTypes->push_back({ "set", "tuple", "terminal" });
    paramTypes->push_back({ "set", "tuple", "terminal" });
    }
	;

EDGE_OP : '->' ;
ASSIGN_OP : ':=' ;
AS_OP : 'as' ;
IF_OP : 'if' ;
ELSE_OP : 'elif' ;

LEFT_TRIANGLE_BRACKET : '<' ;
RIGHT_TRIANGLE_BRACKET : '>' ;
LEFT_SQUARE_BRACKET : '[' ;
RIGHT_SQUARE_BRACKET : ']' ;
LEFT_FIGURE_BRACKET : '{' ;
RIGHT_FIGURE_BRACKET : '}' ;
LEFT_CURL_BRACKET : '(' ;
RIGHT_CURL_BRACKET : ')' ;
COMMA : ',' ;
SEMICOLON : ';' ;

PROCEDURE_TYPE
	: 'procedure'
	;

OBJECT_TYPE
	: 'set'
	| 'terminal'
	| 'tuple'
	;

STRING
	: '\'' NAME '\''
	;

NAME
	: (LETTER | DIGIT)+
	;

LETTER
	: [a-zA-Z_]
	;
DIGIT
	: [0-9]
	;

WS
	: [ \t\n]+ -> skip
	;

SL_COMMENT
    : '//' .*? '\n' -> skip
    ;
