grammar scq;

options
{
  language = Cpp;
}

program : procDeclaration+ procDefinition+ ;

procDeclaration : PROCEDURE_TYPE EDGE_OP NAME (COMMA NAME)* SEMICOLON ;

procDefinition : (PROCEDURE_TYPE EDGE_OP)? NAME ASSIGN_OP procParams COMMA procBody SEMICOLON ;

procParams : LEFT_CURL_BRACKET (OBJECT_TYPE EDGE_OP NAME)* (COMMA (OBJECT_TYPE EDGE_OP)* NAME)* RIGHT_CURL_BRACKET ;

procBody : (objectCreation | command)* ;

objectCreation : objectCreationOperand (COMMA objectCreationOperand)* (EDGE_OP | ASSIGN_OP)
				(compositeOperand (ASSIGN_OP compositeOperand)* | command) SEMICOLON ;

objectCreationOperand : NAME
	| OBJECT_TYPE
	;

command : COMMAND EDGE_OP commandCompositeOperand (COMMA commandCompositeOperand)* SEMICOLON
	| IF_OP EDGE_OP command COMMA (command | objectCreation) (COMMA (command | objectCreation))* SEMICOLON ;

compositeOperand : operand (COMMA operand)* ;

commandCompositeOperand : NAME
	| STRING
    | orientedSet
    | templateCommand
    ;

operand : NAME
	| STRING
	| orientedSet
	| nonOrientedSet
	| templateCommand
	;

nonOrientedSet : LEFT_FIGURE_BRACKET compositeOperand* (COMMA compositeOperand)* RIGHT_FIGURE_BRACKET ;

orientedSet : LEFT_CURL_BRACKET compositeOperand* (COMMA compositeOperand)* RIGHT_CURL_BRACKET ;

templateCommand : templateExpression (COMMA templateExpression)* (commandTemplateResult)? ;

templateExpression : LEFT_SQUARE_BRACKET commandTemplate RIGHT_SQUARE_BRACKET ;

commandTemplate : templateParam (COMMA templateParam)* EDGE_OP templateParam (COMMA templateParam)* ;

commandTemplateResult : AS_OP LEFT_SQUARE_BRACKET templateParam (COMMA templateParam)* RIGHT_SQUARE_BRACKET ;

templateParam : COMMAND
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

COMMAND : 'intersect'
	| 'complement'
	| 'unite'
	| 'remove'
	| 'set_idtf'
	| 'equal'
	| 'dump'
	| 'return'
	;

PROCEDURE_TYPE : 'procedure' ;
OBJECT_TYPE : 'set'
	| 'terminal'
	| 'tuple'
	;

STRING : '\'' NAME '\'' ;

NAME : (LETTER | DIGIT)+ ;

LETTER : [a-zA-Z_] ;
DIGIT : [0-9] ;

WS : [ \t\n]+ -> skip ;

SL_COMMENT
    :   '//' .*? '\n' -> skip
    ;