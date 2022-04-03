
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


// Generated from /home/nikita/CLionProjects/ostis-web-platform/sc-machine/scq/scq/scq.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  scqParser : public antlr4::Parser {
public:
  enum {
    EDGE_OP = 1, ASSIGN_OP = 2, AS_OP = 3, IF_OP = 4, ELSE_OP = 5, LEFT_TRIANGLE_BRACKET = 6, 
    RIGHT_TRIANGLE_BRACKET = 7, LEFT_SQUARE_BRACKET = 8, RIGHT_SQUARE_BRACKET = 9, 
    LEFT_FIGURE_BRACKET = 10, RIGHT_FIGURE_BRACKET = 11, LEFT_CURL_BRACKET = 12, 
    RIGHT_CURL_BRACKET = 13, COMMA = 14, SEMICOLON = 15, SET_OPERATION = 16, 
    PROCEDURE_TYPE = 17, OBJECT_TYPE = 18, STRING = 19, NAME = 20, LETTER = 21, 
    DIGIT = 22, WS = 23, SL_COMMENT = 24
  };

  enum {
    RuleProgram = 0, RuleProcDeclaration = 1, RuleProcDefinition = 2, RuleProcParams = 3, 
    RuleBlock = 4, RuleObjectDeclaration = 5, RuleObjectDefinition = 6, 
    RuleOperation = 7, RuleCompositeOperand = 8, RuleOperationOperand = 9, 
    RuleOperand = 10, RuleNonOrientedSet = 11, RuleOrientedSet = 12, RuleTemplateCommand = 13, 
    RuleTemplateExpression = 14, RuleCommandTemplate = 15, RuleCommandTemplateResult = 16, 
    RuleTemplateParam = 17
  };

  explicit scqParser(antlr4::TokenStream *input);
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
  class OperationOperandContext;
  class OperandContext;
  class NonOrientedSetContext;
  class OrientedSetContext;
  class TemplateCommandContext;
  class TemplateExpressionContext;
  class CommandTemplateContext;
  class CommandTemplateResultContext;
  class TemplateParamContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    using Procedures = std::unordered_set<std::string>;
    using ProcedureDefinitions = std::map<std::string, scqParser::ProcDefinitionContext *>;
    Procedures procs = Procedures();
    ProcedureDefinitions procDefs = ProcedureDefinitions();
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    std::vector<ProcDeclarationContext *> procDeclaration();
    ProcDeclarationContext* procDeclaration(size_t i);
    std::vector<ProcDefinitionContext *> procDefinition();
    ProcDefinitionContext* procDefinition(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ProcDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Procedures procs;
    antlr4::Token *n1 = nullptr;
    antlr4::Token *n2 = nullptr;
    ProcDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ProcDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Procedures procs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROCEDURE_TYPE();
    antlr4::tree::TerminalNode *EDGE_OP();
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcDeclarationContext* procDeclaration(ProgramContext::Procedures procs);

  class  ProcDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::Procedures procs;
    ProgramContext::ProcedureDefinitions procDefs;
    antlr4::Token *nameToken = nullptr;
    ProcDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ProcDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::Procedures procs, ProgramContext::ProcedureDefinitions procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *ASSIGN_OP();
    ProcParamsContext *procParams();
    antlr4::tree::TerminalNode *COMMA();
    BlockContext *block();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *PROCEDURE_TYPE();
    antlr4::tree::TerminalNode *EDGE_OP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcDefinitionContext* procDefinition(ProgramContext::Procedures procs,ProgramContext::ProcedureDefinitions procDefs);

  class  ProcParamsContext : public antlr4::ParserRuleContext {
  public:
    ProcParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcParamsContext* procParams();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext::ProcedureDefinitions procDefs;
    using Objects = std::unordered_set<std::string>;
    using ObjectsDefinitions = std::vector<std::pair<std::string, scqParser::ObjectDefinitionContext *>>;
    Objects objects = Objects();
    ObjectsDefinitions objDefs = ObjectsDefinitions();
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState, ProgramContext::ProcedureDefinitions procDefs);
    virtual size_t getRuleIndex() const override;
    std::vector<ObjectDeclarationContext *> objectDeclaration();
    ObjectDeclarationContext* objectDeclaration(size_t i);
    std::vector<ObjectDefinitionContext *> objectDefinition();
    ObjectDefinitionContext* objectDefinition(size_t i);
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block(ProgramContext::ProcedureDefinitions procDefs);

  class  ObjectDeclarationContext : public antlr4::ParserRuleContext {
  public:
    BlockContext::Objects objects;
    antlr4::Token *nameToken = nullptr;
    ObjectDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ObjectDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState, BlockContext::Objects objects);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> OBJECT_TYPE();
    antlr4::tree::TerminalNode* OBJECT_TYPE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectDeclarationContext* objectDeclaration(BlockContext::Objects objects);

  class  ObjectDefinitionContext : public antlr4::ParserRuleContext {
  public:
    BlockContext::Objects objects;
    BlockContext::ObjectsDefinitions objDefs;
    ProgramContext::ProcedureDefinitions procDefs;
    antlr4::Token *n1 = nullptr;
    antlr4::Token *n2 = nullptr;
    antlr4::Token *n3 = nullptr;
    ObjectDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    ObjectDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState, BlockContext::Objects objects, BlockContext::ObjectsDefinitions objDefs, ProgramContext::ProcedureDefinitions procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *EDGE_OP();
    CompositeOperandContext *compositeOperand();
    OperationContext *operation();
    std::vector<antlr4::tree::TerminalNode *> OBJECT_TYPE();
    antlr4::tree::TerminalNode* OBJECT_TYPE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *ASSIGN_OP();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ObjectDefinitionContext* objectDefinition(BlockContext::Objects objects,BlockContext::ObjectsDefinitions objDefs,ProgramContext::ProcedureDefinitions procDefs);

  class  OperationContext : public antlr4::ParserRuleContext {
  public:
    BlockContext::Objects objects;
    BlockContext::ObjectsDefinitions objDefs;
    ProgramContext::ProcedureDefinitions procDefs;
    antlr4::Token *set_operationToken = nullptr;
    antlr4::Token *nameToken = nullptr;
    antlr4::Token *if_opToken = nullptr;
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    OperationContext(antlr4::ParserRuleContext *parent, size_t invokingState, BlockContext::Objects objects, BlockContext::ObjectsDefinitions objDefs, ProgramContext::ProcedureDefinitions procDefs);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<OperationOperandContext *> operationOperand();
    OperationOperandContext* operationOperand(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *SET_OPERATION();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *IF_OP();
    std::vector<OperationContext *> operation();
    OperationContext* operation(size_t i);
    std::vector<ObjectDefinitionContext *> objectDefinition();
    ObjectDefinitionContext* objectDefinition(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationContext* operation(BlockContext::Objects objects,BlockContext::ObjectsDefinitions objDefs,ProgramContext::ProcedureDefinitions procDefs);

  class  CompositeOperandContext : public antlr4::ParserRuleContext {
  public:
    BlockContext::Objects objects;
    CompositeOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    CompositeOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState, BlockContext::Objects objects);
    virtual size_t getRuleIndex() const override;
    std::vector<OperandContext *> operand();
    OperandContext* operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompositeOperandContext* compositeOperand(BlockContext::Objects objects);

  class  OperationOperandContext : public antlr4::ParserRuleContext {
  public:
    BlockContext::Objects objects;
    antlr4::Token *nameToken = nullptr;
    OperationOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    OperationOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState, BlockContext::Objects objects);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *STRING();
    OrientedSetContext *orientedSet();
    TemplateCommandContext *templateCommand();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperationOperandContext* operationOperand(BlockContext::Objects objects);

  class  OperandContext : public antlr4::ParserRuleContext {
  public:
    BlockContext::Objects objects;
    antlr4::Token *nameToken = nullptr;
    OperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    OperandContext(antlr4::ParserRuleContext *parent, size_t invokingState, BlockContext::Objects objects);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *STRING();
    OrientedSetContext *orientedSet();
    NonOrientedSetContext *nonOrientedSet();
    TemplateCommandContext *templateCommand();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperandContext* operand(BlockContext::Objects objects);

  class  NonOrientedSetContext : public antlr4::ParserRuleContext {
  public:
    std::unordered_set<std::string> objects;
    NonOrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    NonOrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState, std::unordered_set<std::string> objects);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_FIGURE_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_FIGURE_BRACKET();
    std::vector<CompositeOperandContext *> compositeOperand();
    CompositeOperandContext* compositeOperand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonOrientedSetContext* nonOrientedSet(std::unordered_set<std::string> objects);

  class  OrientedSetContext : public antlr4::ParserRuleContext {
  public:
    std::unordered_set<std::string> objects;
    OrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    OrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState, std::unordered_set<std::string> objects);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURL_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_CURL_BRACKET();
    std::vector<CompositeOperandContext *> compositeOperand();
    CompositeOperandContext* compositeOperand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrientedSetContext* orientedSet(std::unordered_set<std::string> objects);

  class  TemplateCommandContext : public antlr4::ParserRuleContext {
  public:
    TemplateCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TemplateExpressionContext *> templateExpression();
    TemplateExpressionContext* templateExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    CommandTemplateResultContext *commandTemplateResult();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplateCommandContext* templateCommand();

  class  TemplateExpressionContext : public antlr4::ParserRuleContext {
  public:
    TemplateExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_SQUARE_BRACKET();
    CommandTemplateContext *commandTemplate();
    antlr4::tree::TerminalNode *RIGHT_SQUARE_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplateExpressionContext* templateExpression();

  class  CommandTemplateContext : public antlr4::ParserRuleContext {
  public:
    CommandTemplateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TemplateParamContext *> templateParam();
    TemplateParamContext* templateParam(size_t i);
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommandTemplateContext* commandTemplate();

  class  CommandTemplateResultContext : public antlr4::ParserRuleContext {
  public:
    CommandTemplateResultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AS_OP();
    antlr4::tree::TerminalNode *LEFT_SQUARE_BRACKET();
    std::vector<TemplateParamContext *> templateParam();
    TemplateParamContext* templateParam(size_t i);
    antlr4::tree::TerminalNode *RIGHT_SQUARE_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommandTemplateResultContext* commandTemplateResult();

  class  TemplateParamContext : public antlr4::ParserRuleContext {
  public:
    TemplateParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET_OPERATION();
    antlr4::tree::TerminalNode *OBJECT_TYPE();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *LEFT_TRIANGLE_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_TRIANGLE_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplateParamContext* templateParam();


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

