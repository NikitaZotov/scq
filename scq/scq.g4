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
	using ProcedureDefinitions = std::map<std::string, scqParser::ProcDefinitionContext *>,
	Procedures * procs = new Procedures(),
	ProcedureDefinitions * procDefs = new ProcedureDefinitions()
	]
	: procDeclaration[$procs]* procDefinition[$procs, $procDefs]* block[$procDefs, {}]
	;
	catch[utils::ScException const & e] {SC_LOG_ERROR("Parse error occurred: " + std::string(e.Message()));}

procDeclaration
	[ProgramContext::Procedures * procs]
	: PROCEDURE_TYPE EDGE_OP NAME
	{
	if ($procs->find($NAME.text) != $procs->end()) {
	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure " + $NAME.text + " is declared.");
	}
	else {
	  $procs->insert($NAME.text);
	  SC_LOG_DEBUG("Declare " + $NAME.text + " procedure");
    }
	}
	(COMMA NAME
	{
    if ($procs->find($NAME.text) != $procs->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure " + $NAME.text + " is declared.");
    }
    else {
      $procs->insert($NAME.text);
      SC_LOG_DEBUG("Declare " + $NAME.text + " procedure");
    }
    }
	)*
	SEMICOLON
	;

procDefinition
	[ProgramContext::Procedures * procs, ProgramContext::ProcedureDefinitions * procDefs]
	locals
    [
    using ProcedureParams = std::unordered_set<std::string>,
    ProcedureParams * params = new ProcedureParams()
    ]
 	: (PROCEDURE_TYPE EDGE_OP)? NAME
 	{
    if ($procs->find($NAME.text) == $procs->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure " + $NAME.text + " isn't declared.");
    }
    else {
      $procDefs->insert({ $NAME.text, $ctx });
      SC_LOG_DEBUG("Define " + $NAME.text + " procedure");
    }
    }
 	ASSIGN_OP procParams[$params] COMMA block[$procDefs, $params]
 	SEMICOLON
 	;

procParams[ProcDefinitionContext::ProcedureParams * params]
	: LEFT_CURL_BRACKET (OBJECT_TYPE EDGE_OP NAME
	{
	if ($params->find($NAME.text) != $params->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param " + $NAME.text + " is repeated.");
    }
    else {
      $params->insert($NAME.text);
      SC_LOG_DEBUG("Define " + $NAME.text + " param");
    }
	}
	)* (COMMA (OBJECT_TYPE EDGE_OP)* NAME
	{
    if ($params->find($NAME.text) != $params->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param " + $NAME.text + " is repeated.");
    }
    else {
      $params->insert($NAME.text);
      SC_LOG_DEBUG("Define " + $NAME.text + " param");
    }
    }
	)* RIGHT_CURL_BRACKET
	;

block
	[ProgramContext::ProcedureDefinitions * procDefs, ProcDefinitionContext::ProcedureParams * params]
	locals
    [
    using Objects = std::unordered_set<std::string>,
    using ObjectsDefinitions = std::vector<std::pair<std::string, scqParser::ObjectDefinitionContext *>>,
    Objects * objects = new Objects(),
    ObjectsDefinitions * objDefs = new ObjectsDefinitions()
    ]
    @init
    {
    $objects->insert($params->begin(), $params->end());
    }
    : (objectDeclaration[$objects, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs] | operation[$objects, $objDefs, $procDefs])*
    ;
    catch[utils::ScException & e] {SC_LOG_ERROR("Parse error occured: " + std::string(e.Message()));}

objectDeclaration
	[BlockContext::Objects * objects, ProgramContext::ProcedureDefinitions * procDefs]
	: OBJECT_TYPE (COMMA (OBJECT_TYPE | (NAME
	{
    if ($objects->find($NAME.text) == $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $NAME.text + " isn't declared.");
    }
    }
	)))* EDGE_OP NAME
	{
    if ($objects->find($NAME.text) != $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $NAME.text + " is declared.");
    }
    else {
      $objects->insert($NAME.text);
      SC_LOG_DEBUG("Declare " + $NAME.text + " object");
    }
    }
    (COMMA NAME
    {
    if ($objects->find($NAME.text) != $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $NAME.text + " is declared.");
    }
    else {
      $objects->insert($NAME.text);
      SC_LOG_DEBUG("Declare " + $NAME.text + " object");
    }
    }
    )*
	SEMICOLON
	;

objectDefinition
	[BlockContext::Objects * objects, BlockContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs]
	: (((OBJECT_TYPE | (n1=NAME
	{
	if ($objects->find($n1.text) == $objects->end() && $procDefs->find($n1.text) == $procDefs->end()) {
	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $n1.text + " isn't declared.");
	}
	else {
      SC_LOG_DEBUG("Define " + $n1.text + " object");
	  objDefs->push_back({ $n1.text, $ctx });
    }
    }
	)) (COMMA (OBJECT_TYPE | (n2=NAME
	{
    if ($objects->find($n2.text) == $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $n2.text + " isn't declared.");
    }
    else {
      SC_LOG_DEBUG("Define " + $n2.text + " object");
      objDefs->push_back({ $n2.text, $ctx });
    }
   	}
	)))* EDGE_OP compositeOperand[$objects])
	| ((n3=NAME
	{
    if ($objects->find($n3.text) == $objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $n3.text + " isn't declared.");
    }
    else {
      SC_LOG_DEBUG("Define " + $n3.text + " object");
      objDefs->push_back({ $n3.text, $ctx });
    }
    }
	ASSIGN_OP)? compositeOperand[$objects]
	| operation[$objects, $objDefs, $procDefs]))
	SEMICOLON
	;

operation
	[BlockContext::Objects * objects, BlockContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs]
 	: (SET_OPERATION | (NAME
 	{
 	if ($procDefs->find($NAME.text) == $procDefs->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure " + $NAME.text + " isn't declared.");
    }
	}
 	)) EDGE_OP operationOperand[$objects]
 	(COMMA operationOperand[$objects])*
 	{
    if ($NAME != nullptr) {
      SC_LOG_DEBUG("Define " + $NAME.text + " operation");
      objDefs->push_back({ $NAME.text, dynamic_cast<ObjectDefinitionContext *>($ctx->parent) });
    }
    else {
      SC_LOG_DEBUG("Define " + $SET_OPERATION.text + " operation");
      objDefs->push_back({ $SET_OPERATION.text, dynamic_cast<ObjectDefinitionContext *>($ctx->parent) });
    }
    }
 	SEMICOLON
	| IF_OP EDGE_OP operation[$objects, $objDefs, $procDefs]
	COMMA (operation[$objects, $objDefs, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs])
	(COMMA (operation[$objects, $objDefs, $procDefs] | objectDefinition[$objects, $objDefs, $procDefs]))*
	{
	  SC_LOG_DEBUG("Define " + $IF_OP.text + " operation");
      objDefs->push_back({ $IF_OP.text, dynamic_cast<ObjectDefinitionContext *>($ctx->parent) });
	}
	SEMICOLON 
	;

compositeOperand[BlockContext::Objects * objects]
 	: operand[$objects] (COMMA operand[$objects])* 
 	;

operationOperand[BlockContext::Objects * objects]
 	: NAME
 	{
    if (objects->find($NAME.text) == objects->end()) {
      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $NAME.text + " isn't declared.");
    }
    }
	| STRING
    | orientedSet[$objects]
    | templateCommand
    ;

operand[BlockContext::Objects * objects]
 	: NAME
 	{
	if (objects->find($NAME.text) == objects->end()) {
	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + $NAME.text + " isn't declared.");
	}
	}
	| STRING
	| orientedSet[$objects]
	| nonOrientedSet[$objects]
	| templateCommand
	;

nonOrientedSet[BlockContext::Objects * objects]
 	: LEFT_FIGURE_BRACKET compositeOperand[$objects]* (COMMA compositeOperand[$objects])* RIGHT_FIGURE_BRACKET 
 	;

orientedSet[BlockContext::Objects * objects]
	: LEFT_CURL_BRACKET compositeOperand[$objects]* (COMMA compositeOperand[$objects])* RIGHT_CURL_BRACKET 
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
	: SET_OPERATION
	| OBJECT_TYPE
	| NAME
	| (LEFT_TRIANGLE_BRACKET NAME RIGHT_TRIANGLE_BRACKET)
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

SET_OPERATION
	: 'intersect'
	| 'complement'
	| 'unite'
	| 'remove'
	| 'set_idtf'
	| 'equal'
	| 'dump'
	| 'return'
	;

PROCEDURE_TYPE
	: 'procedure'
	;

OBJECT_TYPE : 'set'
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