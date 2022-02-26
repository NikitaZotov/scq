
// Generated from scq.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace scq {


class  scqParser : public antlr4::Parser {
public:
  enum {
    EDGE_OP = 1, ASSIGN_OP = 2, AS_OP = 3, LEFT_TRIANGLE_BRACKET = 4, RIGHT_TRIANGLE_BRACKET = 5, 
    LEFT_SQUARE_BRACKET = 6, RIGHT_SQUARE_BRACKET = 7, LEFT_FIGURE_BRACKET = 8, 
    RIGHT_FIGURE_BRACKET = 9, LEFT_CURL_BRACKET = 10, RIGHT_CURL_BRACKET = 11, 
    COMMA = 12, SEMICOLON = 13, COMMAND = 14, PROCEDURE_TYPE = 15, OBJECT_TYPE = 16, 
    STRING = 17, NAME = 18, LETTER = 19, DIGIT = 20, WS = 21, SL_COMMENT = 22
  };

  enum {
    RuleProgram = 0, RuleProcDeclaration = 1, RuleProcDefinition = 2, RuleProcParams = 3, 
    RuleProcBody = 4, RuleObjectCreation = 5, RuleObjectCreationOperand = 6, 
    RuleCommand = 7, RuleCompositeOperand = 8, RuleCommandCompositeOperand = 9, 
    RuleOperand = 10, RuleNonOrientedSet = 11, RuleOrientedSet = 12, RuleTemplateCommand = 13, 
    RuleTemplateExpression = 14, RuleCommandTemplate = 15, RuleCommandTemplateResult = 16, 
    RuleTemplateParam = 17
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
  class ProcBodyContext;
  class ObjectCreationContext;
  class ObjectCreationOperandContext;
  class CommandContext;
  class CompositeOperandContext;
  class CommandCompositeOperandContext;
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
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ProcDeclarationContext *> procDeclaration();
    ProcDeclarationContext* procDeclaration(size_t i);
    std::vector<ProcDefinitionContext *> procDefinition();
    ProcDefinitionContext* procDefinition(size_t i);

   
  };

  ProgramContext* program();

  class  ProcDeclarationContext : public antlr4::ParserRuleContext {
  public:
    ProcDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROCEDURE_TYPE();
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<antlr4::tree::TerminalNode *> NAME();
    antlr4::tree::TerminalNode* NAME(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  ProcDeclarationContext* procDeclaration();

  class  ProcDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ProcDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *ASSIGN_OP();
    ProcParamsContext *procParams();
    antlr4::tree::TerminalNode *COMMA();
    ProcBodyContext *procBody();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *PROCEDURE_TYPE();
    antlr4::tree::TerminalNode *EDGE_OP();

   
  };

  ProcDefinitionContext* procDefinition();

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

   
  };

  ProcParamsContext* procParams();

  class  ProcBodyContext : public antlr4::ParserRuleContext {
  public:
    ProcBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ObjectCreationContext *> objectCreation();
    ObjectCreationContext* objectCreation(size_t i);
    std::vector<CommandContext *> command();
    CommandContext* command(size_t i);

   
  };

  ProcBodyContext* procBody();

  class  ObjectCreationContext : public antlr4::ParserRuleContext {
  public:
    ObjectCreationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ObjectCreationOperandContext *> objectCreationOperand();
    ObjectCreationOperandContext* objectCreationOperand(size_t i);
    std::vector<CompositeOperandContext *> compositeOperand();
    CompositeOperandContext* compositeOperand(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<antlr4::tree::TerminalNode *> ASSIGN_OP();
    antlr4::tree::TerminalNode* ASSIGN_OP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  ObjectCreationContext* objectCreation();

  class  ObjectCreationOperandContext : public antlr4::ParserRuleContext {
  public:
    ObjectCreationOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *OBJECT_TYPE();

   
  };

  ObjectCreationOperandContext* objectCreationOperand();

  class  CommandContext : public antlr4::ParserRuleContext {
  public:
    CommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMAND();
    antlr4::tree::TerminalNode *EDGE_OP();
    std::vector<CommandCompositeOperandContext *> commandCompositeOperand();
    CommandCompositeOperandContext* commandCompositeOperand(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  CommandContext* command();

  class  CompositeOperandContext : public antlr4::ParserRuleContext {
  public:
    CompositeOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OperandContext *> operand();
    OperandContext* operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  CompositeOperandContext* compositeOperand();

  class  CommandCompositeOperandContext : public antlr4::ParserRuleContext {
  public:
    CommandCompositeOperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *STRING();
    OrientedSetContext *orientedSet();
    TemplateCommandContext *templateCommand();

   
  };

  CommandCompositeOperandContext* commandCompositeOperand();

  class  OperandContext : public antlr4::ParserRuleContext {
  public:
    OperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *STRING();
    OrientedSetContext *orientedSet();
    NonOrientedSetContext *nonOrientedSet();
    TemplateCommandContext *templateCommand();

   
  };

  OperandContext* operand();

  class  NonOrientedSetContext : public antlr4::ParserRuleContext {
  public:
    NonOrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_FIGURE_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_FIGURE_BRACKET();
    std::vector<CompositeOperandContext *> compositeOperand();
    CompositeOperandContext* compositeOperand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  NonOrientedSetContext* nonOrientedSet();

  class  OrientedSetContext : public antlr4::ParserRuleContext {
  public:
    OrientedSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_CURL_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_CURL_BRACKET();
    std::vector<CompositeOperandContext *> compositeOperand();
    CompositeOperandContext* compositeOperand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

   
  };

  OrientedSetContext* orientedSet();

  class  TemplateCommandContext : public antlr4::ParserRuleContext {
  public:
    TemplateCommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TemplateExpressionContext *> templateExpression();
    TemplateExpressionContext* templateExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    CommandTemplateResultContext *commandTemplateResult();

   
  };

  TemplateCommandContext* templateCommand();

  class  TemplateExpressionContext : public antlr4::ParserRuleContext {
  public:
    TemplateExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_SQUARE_BRACKET();
    CommandTemplateContext *commandTemplate();
    antlr4::tree::TerminalNode *RIGHT_SQUARE_BRACKET();

   
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

   
  };

  CommandTemplateResultContext* commandTemplateResult();

  class  TemplateParamContext : public antlr4::ParserRuleContext {
  public:
    TemplateParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMAND();
    antlr4::tree::TerminalNode *OBJECT_TYPE();
    antlr4::tree::TerminalNode *NAME();
    antlr4::tree::TerminalNode *LEFT_TRIANGLE_BRACKET();
    antlr4::tree::TerminalNode *RIGHT_TRIANGLE_BRACKET();

   
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

}  // namespace scq
