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
	using ProcedureDefinitions = std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>> *>,
	Procedures * procs = new Procedures(),
	ProcedureDefinitions * procDefs = new ProcedureDefinitions()
	]
	: procDeclaration[$procs]* procDefinition[$procs, $procDefs]* block[$procDefs, nullptr]
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
    ProcedureParams * params = new ProcedureParams()
    ]
 	: (PROCEDURE_TYPE EDGE_OP)? NAME
 	{
    if ($procs->find($NAME.text) == $procs->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + $NAME.text + "\" isn't declared.");
    }
    }
 	ASSIGN_OP procParams[$params] COMMA block[$procDefs, $params]
 	{
 	$procDefs->insert({ $NAME.text, $params });
    SC_LOG_DEBUG("Define \"" + $NAME.text + "\" procedure");
 	}
 	SEMICOLON
 	;

procParams[ProcDefinitionContext::ProcedureParams * params]
	: LEFT_CURL_BRACKET (OBJECT_TYPE EDGE_OP NAME
	{
	if (std::find_if($params->begin(), $params->end(), [&](auto & item) -> bool { item.first == $NAME.text; }) != $params->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param \"" + $NAME.text + "\" is repeated.");
    }
    else {
      $params->push_back({ $NAME.text, $OBJECT_TYPE.text });
      SC_LOG_DEBUG("Define \"" + $NAME.text + "\" param");
    }
	}
	)* (COMMA (OBJECT_TYPE EDGE_OP)* NAME
	{
    if (std::find_if($params->begin(), $params->end(), [&](auto & item) -> bool { item.first == $NAME.text; }) != $params->end()) {
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
	[ProgramContext::ProcedureDefinitions * procDefs, ProcDefinitionContext::ProcedureParams * params]
	locals
    [
    using Objects = std::unordered_map<std::string, std::string>,
    using ObjectsDefinitions = std::vector<std::pair<std::string, scqParser::ObjectDefinitionContext *>>,
    Objects * objects = new Objects(),
    ObjectsDefinitions * objDefs = new ObjectsDefinitions()
    ]
    @init
    {
    if (params != nullptr) {
      std::for_each(params->begin(), params->end(), [&](const auto & item) {
        $objects->insert(item);
      });
    }
    }
    : (objectDeclaration[$objects, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs] | operation[$objects, $objDefs, $procDefs])*
    ;
    //catch[utils::ScException & e] {SC_LOG_ERROR("Parse error occured: " + std::string(e.Message()));}

objectDeclaration
	[BlockContext::Objects * objects, ProgramContext::ProcedureDefinitions * procDefs]
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
	[BlockContext::Objects * objects, BlockContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs]
	locals
	[
	size_t paramNum = 0,
	ProcDefinitionContext::ProcedureParams funcParams
	]
	: (((OBJECT_TYPE | (n1=NAME
	{
	auto const & it = $procDefs->find($n1.text);
	if (it != $procDefs->end()) {
	  $funcParams = *(*procDefs->find($n1.text)).second;
	  SC_LOG_DEBUG("Define \"" + $n1.text + "\" function call");
	  $objDefs->push_back({ $n1.text, $ctx });
	}
	else if ($objects->find($n1.text) == $objects->end()) {
	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $n1.text + "\" isn't declared.");
    }
	else {
      SC_LOG_DEBUG("Define \"" + $n1.text + "\" object");
	  $objDefs->push_back({ $n1.text, $ctx });
    }
    }
	)) (COMMA (OBJECT_TYPE | (n2=NAME
	{
    if ($objects->find($n2.text) == $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $n2.text + "\" isn't declared.");
    }
    else {
      SC_LOG_DEBUG("Define \"" + $n2.text + "\" object");
      $objDefs->push_back({ $n2.text, $ctx });
    }
   	}
	)))* EDGE_OP compositeOperand[$objects, &$paramNum, &$funcParams])
	{
	if ($paramNum > $funcParams.size()) {
	  SC_THROW_EXCEPTION(
	    utils::ExceptionInvalidParams,
	    "Expected " + std::to_string($funcParams.size()) + " params. Gotten " + std::to_string($paramNum) + ".");
	}
	}
	| ((n3=NAME
	{
    if ($objects->find($n3.text) == $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + $n3.text + "\" isn't declared.");
    }
    else {
      SC_LOG_DEBUG("Define \"" + $n3.text + "\" object");
      $objDefs->push_back({ $n3.text, $ctx });
    }
    }
	ASSIGN_OP)? compositeOperand[$objects, &$paramNum, &$funcParams]
	| operation[$objects, $objDefs, $procDefs]))
	SEMICOLON
	;

operation
	[BlockContext::Objects * objects, BlockContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs]
	locals
	[
	size_t paramNum = 0,
	std::vector<std::vector<std::string>> paramTypes,
    ]
 	: (setOperation[&$paramTypes] | (NAME
 	{
 	if ($procDefs->find($NAME.text) == $procDefs->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure " + $NAME.text + " isn't declared.");
    }
	}
 	)) EDGE_OP operationOperand[$objects, &$paramNum, &$paramTypes]
 	(COMMA operationOperand[$objects, &$paramNum, &$paramTypes])*
 	{
    if ($NAME != nullptr) {
      SC_LOG_DEBUG("Define \"" + $NAME.text + "\" operation");
      $objDefs->push_back({ $NAME.text, dynamic_cast<ObjectDefinitionContext *>($ctx->parent) });
    }
    else {
      SC_LOG_DEBUG("Define \"" + $setOperation.text + "\" operation");
      $objDefs->push_back({ $setOperation.text, dynamic_cast<ObjectDefinitionContext *>($ctx->parent) });
    }
    }
 	SEMICOLON
 	{
    if ($paramNum > $paramTypes.size()) {
      SC_THROW_EXCEPTION(
        utils::ExceptionInvalidParams,
    	"Expected " + std::to_string($paramTypes.size()) + " params. Gotten " + std::to_string($paramNum) + ".");
    }
    }
	| IF_OP EDGE_OP operation[$objects, $objDefs, $procDefs]
	COMMA (operation[$objects, $objDefs, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs])
	(COMMA (operation[$objects, $objDefs, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs]))*
	{
	  SC_LOG_DEBUG("Define \"" + $IF_OP.text + "\" operation");
      $objDefs->push_back({ $IF_OP.text, dynamic_cast<ObjectDefinitionContext *>($ctx->parent) });
	}
	SEMICOLON 
	;

compositeOperand[BlockContext::Objects * objects, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params]
 	: operand[$objects, $paramNum, $params] (COMMA operand[$objects, $paramNum, $params])*
 	;

operationOperand[BlockContext::Objects * objects, size_t * paramNum, std::vector<std::vector<std::string>> * params]
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
	        "Unexpected param \"" + $NAME.text + "\" with type \"" + type + "\" in function call. Expected param with type \"" + expectedTypes.at(0) + "\".");
	    }
      }
      ++(*$paramNum);
    }
    }
	| (STRING
	{
	if (paramNum != nullptr && params != nullptr) {
      if (*paramNum < params->size()) {
    	std::vector<std::string> & expectedTypes = $params->at(*$paramNum);
    	if (std::find(expectedTypes.begin(), expectedTypes.end(), "string") == expectedTypes.end()) {
    	  SC_THROW_EXCEPTION(
    	    utils::ExceptionInvalidParams,
    	    "Unexpected param \"" + $STRING.text + "\" with type \"string\" in function call. Expected param with type \"" + expectedTypes.at(0) + "\".");
    	}
      }
      ++(*$paramNum);
    }
    })
    | orientedSet[$objects, nullptr, nullptr]
    | templateCommand
    ;

operand[BlockContext::Objects * objects, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params]
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
	        "Unexpected param \"" + $NAME.text + "\" with type \"" + type + "\" in function call. Expected param with type \"" + expectedType + "\".");
	    }
      }
      ++(*$paramNum);
    }
	}
	| STRING
	| orientedSet[$objects, $paramNum, $params]
	| nonOrientedSet[$objects, $paramNum, $params]
	| templateCommand
	;

nonOrientedSet[BlockContext::Objects * objects, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params]
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
 	compositeOperand[$objects, nullptr, nullptr]* (COMMA compositeOperand[$objects, nullptr, nullptr])* RIGHT_FIGURE_BRACKET
 	;

orientedSet[BlockContext::Objects * objects, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params]
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
	compositeOperand[$objects, nullptr, nullptr]* (COMMA compositeOperand[$objects, nullptr, nullptr])* RIGHT_CURL_BRACKET
	;

templateCommand
	: templateExpression (COMMA templateExpression)* (commandTemplateResult)? 
	;

templateExpression
	: LEFT_SQUARE_BRACKET commandTemplate RIGHT_SQUARE_BRACKET 
	;

commandTemplate
	: templateParam (COMMA templateParam)* EDGE_OP templateParam (COMMA templateParam)* 
	;

commandTemplateResult
	: AS_OP LEFT_SQUARE_BRACKET templateParam (COMMA templateParam)* RIGHT_SQUARE_BRACKET 
	;

templateParam
	locals
	[
	size_t paramNum = 0,
	std::vector<std::vector<std::string>> paramTypes,
    ProcDefinitionContext::ProcedureParams operationParams
    ]
	: setOperation[&$paramTypes]
	| OBJECT_TYPE
	| NAME
	| (LEFT_TRIANGLE_BRACKET NAME RIGHT_TRIANGLE_BRACKET)
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
	| 'equal'
	{
	paramTypes->push_back({ "set", "tuple", "terminal" });
    paramTypes->push_back({ "set", "tuple", "terminal" });
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