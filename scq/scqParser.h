
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


// Generated from scq.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace scq {


class  scqParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, EDGE_OP = 10, ASSIGN_OP = 11, AS_OP = 12, IF_OP = 13, 
    ELSE_OP = 14, LEFT_TRIANGLE_BRACKET = 15, RIGHT_TRIANGLE_BRACKET = 16, 
    LEFT_SQUARE_BRACKET = 17, RIGHT_SQUARE_BRACKET = 18, LEFT_FIGURE_BRACKET = 19, 
    RIGHT_FIGURE_BRACKET = 20, LEFT_CURL_BRACKET = 21, RIGHT_CURL_BRACKET = 22, 
    COMMA = 23, SEMICOLON = 24, PROCEDURE_TYPE = 25, OBJECT_TYPE = 26, STRING = 27, 
    NAME = 28, LETTER = 29, DIGIT = 30, WS = 31, SL_COMMENT = 32
  };

  enum {
    RuleProgram = 0, RuleProcDeclaration = 1, RuleProcDefinition = 2, RuleProcParams = 3, 
    RuleBlock = 4, RuleObjectDeclaration = 5, RuleObjectDefinition = 6, 
    RuleOperation = 7, RuleCompositeOperand = 8, RuleAssignable = 9, RuleOperationOperand = 10, 
    RuleOperand = 11, RuleNonOrientedSet = 12, RuleOrientedSet = 13, RuleTemplateCommand = 14, 
    RuleTemplateExpression = 15, RuleCommandTemplate = 16, RuleCommandTemplateResult = 17, 
    RuleTemplateParam = 18, RuleSetOperation = 19
  };

  scqParser(antlr4::TokenStream *input);
  ~scqParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class ProcDeclarationContext;
  class ProcDefinitionContext;
  class ProcParamsContext;
  class BlockContext;
  class ObjectDeclarationContext;
  class ObjectDefinitionContext;
  class OperationContext;
  class CompositeOperandContext;
  class AssignableContext;
  class OperationOperandContext;
  class OperandContext;
  class NonOrientedSetContext;
  class OrientedSetContext;
  class TemplateCommandContext;
  class TemplateExpressionContext;
  class CommandTemplateContext;
  class CommandTemplateResultContext;
  class TemplateParamContext;
  class SetOperationContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    using Procedures = std::unordered_set<std::string>;
    Procedures * procs = new Procedures();
    using ObjectsDefinitions = std::vector<std::array<std::string, 4>>;
    ObjectsDefinitions * objDefs = new ObjectsDefinitions();
    using Objects = std::unordered_map<std::string, std::string>;
    Objects * objects = new Objects();
    using ProcedureDefinitions = std::unordered_map<
    			std::string,
    			std::pair<
    				std::vector<std::pair<std::string, std::string>> *,
    				std::pair<ProgramContext::ObjectsDefinitions *, ProgramContext::Objects *>
    			>
    		>;
    ProcedureDefinitions * procDefs = new ProcedureDefinitions();
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    std::vector<ProcDeclarationContext *> procDeclaration();
    ProcDeclarationContext* procDeclaration(size_t i);
    std::vector<ProcDefinitionContext *> procDefinition();
    ProcDefinitionContext* procDefinition(size_t i);

   
  };

  ProgramContext* program();

  class  ProcDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Procedures * procs;
    antlr4::Token *nameToken = nullptr;;
    ProcDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ProcDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Procedures * procs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROCEDURE_TYPE();
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  ProcDeclarationContext* procDeclaration(ProgramContext::Procedures * procs);

  class  ProcDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Procedures * procs;
    ProgramContext::ProcedureDefinitions * procDefs;
    using ProcedureParams = std::vector<std::pair<std::string, std::string>>;
    ProcedureParams * params = new ProcedureParams();
    ProgramContext::ObjectsDefinitions * objDefs = new ProgramContext::ObjectsDefinitions();
    ProgramContext::Objects * objects = new ProgramContext::Objects();
    antlr4::Token *nameToken = nullptr;;
    ProcDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ProcDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Procedures * procs, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *ASSIGN_OP();
    ProcParamsContext *procParams();
    antlr4::tree::TerminalNode *COMMA();
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *PROCEDURE_TYPE();
    antlr4::tree::TerminalNode *EDGE_OP();

   
  };

  ProcDefinitionContext* procDefinition(ProgramContext::Procedures * procs,ProgramContext::ProcedureDefinitions * procDefs);

  class  ProcParamsContext : public antlr4::ParserRuleContext {
  public:
    ProcDefinitionContext::ProcedureParams * params;
    antlr4::Token *object_typeToken = nullptr;;
    antlr4::Token *nameToken = nullptr;;
    ProcParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ProcParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProcDefinitionContext::ProcedureParams * params);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURL_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_CURL_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> OBJECT_TYPE();
    antlr4::tree::TerminalNode* OBJECT_TYPE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EDGE_OP();
    antlr4::tree::TerminalNode* EDGE_OP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  ProcParamsContext* procParams(ProcDefinitionContext::ProcedureParams * params);

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::ProcedureDefinitions * procDefs;
    ProcDefinitionContext::ProcedureParams * params;
    ProgramContext::ObjectsDefinitions * objDefs;
    ProgramContext::Objects * objects;
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::ProcedureDefinitions * procDefs, ProcDefinitionContext::ProcedureParams * params, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::Objects * objects);
    virtual size_t getRuleIndex() const override;
    std::vector<ObjectDeclarationContext *> objectDeclaration();
    ObjectDeclarationContext* objectDeclaration(size_t i);
    std::vector<ObjectDefinitionContext *> objectDefinition();
    ObjectDefinitionContext* objectDefinition(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);

   
  };

  BlockContext* block(ProgramContext::ProcedureDefinitions * procDefs,ProcDefinitionContext::ProcedureParams * params,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::Objects * objects);

  class  ObjectDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ProcedureDefinitions * procDefs;
    antlr4::Token *object_typeToken = nullptr;;
    antlr4::Token *nameToken = nullptr;;
    ObjectDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ObjectDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OBJECT_TYPE();
    antlr4::tree::TerminalNode* OBJECT_TYPE(size_t i);
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  ObjectDeclarationContext* objectDeclaration(ProgramContext::Objects * objects,ProgramContext::ProcedureDefinitions * procDefs);

  class  ObjectDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    ProgramContext::ProcedureDefinitions * procDefs;
    size_t paramNum = 0;
    ProcDefinitionContext::ProcedureParams * funcParams = new ProcDefinitionContext::ProcedureParams();
    size_t depth = 0;
    antlr4::Token *n0 = nullptr;;
    antlr4::Token *n1 = nullptr;;
    antlr4::Token *n3 = nullptr;;
    scqParser::OperationContext *o1 = nullptr;;
    ObjectDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ObjectDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *EDGE_OP();
    CompositeOperandContext *compositeOperand();
    antlr4::tree::TerminalNode *OBJECT_TYPE();
    AssignableContext *assignable();
    OperationContext *operation();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *ASSIGN_OP();

   
  };

  ObjectDefinitionContext* objectDefinition(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs);

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    ProgramContext::ProcedureDefinitions * procDefs;
    std::string name;
    size_t paramNum = 0;
    std::vector<std::vector<std::string>> paramTypes;
    size_t depth = 0;
    scqParser::SetOperationContext *o1 = nullptr;;
    scqParser::SetOperationContext *setOperationContext = nullptr;;
    antlr4::Token *if_opToken = nullptr;;
    antlr4::Token *else_opToken = nullptr;;
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> EDGE_OP();
    antlr4::tree::TerminalNode* EDGE_OP(size_t i);
    TemplateCommandContext *templateCommand();
    SetOperationContext *setOperation();
    antlr4::tree::TerminalNode *LEFT_CURL_BRACKET();
    std::vector<OperationOperandContext *> operationOperand();
    OperationOperandContext* operationOperand(size_t i);
    antlr4::tree::TerminalNode *RIGHT_CURL_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *IF_OP();
    std::vector<TemplateExpressionContext *> templateExpression();
    TemplateExpressionContext* templateExpression(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<ObjectDefinitionContext *> objectDefinition();
    ObjectDefinitionContext* objectDefinition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELSE_OP();
    antlr4::tree::TerminalNode* ELSE_OP(size_t i);

   
  };

  OperationContext* operation(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs);

  class  CompositeOperandContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    size_t * paramNum;
    ProcDefinitionContext::ProcedureParams * params;
    size_t depth;
    CompositeOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    CompositeOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURL_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_CURL_BRACKET();
    std::vector<OperandContext *> operand();
    OperandContext* operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  CompositeOperandContext* compositeOperand(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth);

  class  AssignableContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    size_t * paramNum;
    ProcDefinitionContext::ProcedureParams * params;
    size_t depth;
    AssignableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    AssignableContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURL_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_CURL_BRACKET();
    std::vector<OperandContext *> operand();
    OperandContext* operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *LEFT_FIGURE_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_FIGURE_BRACKET();

   
  };

  AssignableContext* assignable(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth);

  class  OperationOperandContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    size_t * paramNum;
    std::vector<std::vector<std::string>> * params;
    size_t depth;
    antlr4::Token *nameToken = nullptr;;
    antlr4::Token *stringToken = nullptr;;
    OperationOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    OperationOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, std::vector<std::vector<std::string>> * params, size_t depth);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *STRING();

   
  };

  OperationOperandContext* operationOperand(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,std::vector<std::vector<std::string>> * params,size_t depth);

  class  OperandContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    size_t * paramNum;
    ProcDefinitionContext::ProcedureParams * params;
    size_t depth;
    antlr4::Token *nameToken = nullptr;;
    OperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    OperandContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *STRING();
    OrientedSetContext *orientedSet();
    NonOrientedSetContext *nonOrientedSet();

   
  };

  OperandContext* operand(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth);

  class  NonOrientedSetContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    size_t * paramNum;
    ProcDefinitionContext::ProcedureParams * params;
    size_t depth;
    NonOrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    NonOrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_FIGURE_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_FIGURE_BRACKET();
    std::vector<OperandContext *> operand();
    OperandContext* operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  NonOrientedSetContext* nonOrientedSet(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth);

  class  OrientedSetContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    size_t * paramNum;
    ProcDefinitionContext::ProcedureParams * params;
    size_t depth;
    OrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    OrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURL_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_CURL_BRACKET();
    std::vector<OperandContext *> operand();
    OperandContext* operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  OrientedSetContext* orientedSet(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth);

  class  TemplateCommandContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    ProgramContext::ProcedureDefinitions * procDefs;
    TemplateCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    TemplateCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    TemplateExpressionContext *templateExpression();
    CommandTemplateResultContext *commandTemplateResult();

   
  };

  TemplateCommandContext* templateCommand(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs);

  class  TemplateExpressionContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    ProgramContext::ProcedureDefinitions * procDefs;
    TemplateExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    TemplateExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_SQUARE_BRACKET();
    std::vector<CommandTemplateContext *> commandTemplate();
    CommandTemplateContext* commandTemplate(size_t i);
    antlr4::tree::TerminalNode *RIGHT_SQUARE_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  TemplateExpressionContext* templateExpression(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs);

  class  CommandTemplateContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    ProgramContext::ProcedureDefinitions * procDefs;
    scqParser::TemplateParamContext *source = nullptr;;
    scqParser::TemplateParamContext *target = nullptr;;
    CommandTemplateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    CommandTemplateContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<TemplateParamContext *> templateParam();
    TemplateParamContext* templateParam(size_t i);

   
  };

  CommandTemplateContext* commandTemplate(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs);

  class  CommandTemplateResultContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    ProgramContext::ProcedureDefinitions * procDefs;
    CommandTemplateResultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    CommandTemplateResultContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AS_OP();
    antlr4::tree::TerminalNode *LEFT_SQUARE_BRACKET();
    std::vector<TemplateParamContext *> templateParam();
    TemplateParamContext* templateParam(size_t i);
    antlr4::tree::TerminalNode *RIGHT_SQUARE_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  CommandTemplateResultContext* commandTemplateResult(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs);

  class  TemplateParamContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Objects * objects;
    ProgramContext::ObjectsDefinitions * objDefs;
    ProgramContext::ProcedureDefinitions * procDefs;
    std::string param;
    antlr4::Token *n1 = nullptr;;
    antlr4::Token *n2 = nullptr;;
    TemplateParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    TemplateParamContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OBJECT_TYPE();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *LEFT_TRIANGLE_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_TRIANGLE_BRACKET();

   
  };

  TemplateParamContext* templateParam(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs);

  class  SetOperationContext : public antlr4::ParserRuleContext {
  public:
    std::vector<std::vector<std::string>> * paramTypes;
    SetOperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    SetOperationContext(antlr4::ParserRuleContext *parent, size_t invokingState, std::vector<std::vector<std::string>> * paramTypes);
    virtual size_t getRuleIndex() const override;

   
  };

  SetOperationContext* setOperation(std::vector<std::vector<std::string>> * paramTypes);


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace scq
