
// Generated from scq.g4 by ANTLR 4.7.1



#include "scqParser.h"


using namespace antlrcpp;
using namespace scq;
using namespace antlr4;

scqParser::scqParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

scqParser::~scqParser() {
  delete _interpreter;
}

std::string scqParser::getGrammarFileName() const {
  return "scq.g4";
}

const std::vector<std::string>& scqParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& scqParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

scqParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scqParser::ProcDeclarationContext *> scqParser::ProgramContext::procDeclaration() {
  return getRuleContexts<scqParser::ProcDeclarationContext>();
}

scqParser::ProcDeclarationContext* scqParser::ProgramContext::procDeclaration(size_t i) {
  return getRuleContext<scqParser::ProcDeclarationContext>(i);
}

std::vector<scqParser::ProcDefinitionContext *> scqParser::ProgramContext::procDefinition() {
  return getRuleContexts<scqParser::ProcDefinitionContext>();
}

scqParser::ProcDefinitionContext* scqParser::ProgramContext::procDefinition(size_t i) {
  return getRuleContext<scqParser::ProcDefinitionContext>(i);
}


size_t scqParser::ProgramContext::getRuleIndex() const {
  return scqParser::RuleProgram;
}


scqParser::ProgramContext* scqParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, scqParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(37); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(36);
              procDeclaration();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(39); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(42); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(41);
      procDefinition();
      setState(44); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == scqParser::PROCEDURE_TYPE

    || _la == scqParser::NAME);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcDeclarationContext ------------------------------------------------------------------

scqParser::ProcDeclarationContext::ProcDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::ProcDeclarationContext::PROCEDURE_TYPE() {
  return getToken(scqParser::PROCEDURE_TYPE, 0);
}

tree::TerminalNode* scqParser::ProcDeclarationContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}

std::vector<tree::TerminalNode *> scqParser::ProcDeclarationContext::NAME() {
  return getTokens(scqParser::NAME);
}

tree::TerminalNode* scqParser::ProcDeclarationContext::NAME(size_t i) {
  return getToken(scqParser::NAME, i);
}

tree::TerminalNode* scqParser::ProcDeclarationContext::SEMICOLON() {
  return getToken(scqParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> scqParser::ProcDeclarationContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::ProcDeclarationContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::ProcDeclarationContext::getRuleIndex() const {
  return scqParser::RuleProcDeclaration;
}


scqParser::ProcDeclarationContext* scqParser::procDeclaration() {
  ProcDeclarationContext *_localctx = _tracker.createInstance<ProcDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, scqParser::RuleProcDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(scqParser::PROCEDURE_TYPE);
    setState(47);
    match(scqParser::EDGE_OP);
    setState(48);
    match(scqParser::NAME);
    setState(53);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(49);
      match(scqParser::COMMA);
      setState(50);
      match(scqParser::NAME);
      setState(55);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(56);
    match(scqParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcDefinitionContext ------------------------------------------------------------------

scqParser::ProcDefinitionContext::ProcDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::ProcDefinitionContext::NAME() {
  return getToken(scqParser::NAME, 0);
}

tree::TerminalNode* scqParser::ProcDefinitionContext::ASSIGN_OP() {
  return getToken(scqParser::ASSIGN_OP, 0);
}

scqParser::ProcParamsContext* scqParser::ProcDefinitionContext::procParams() {
  return getRuleContext<scqParser::ProcParamsContext>(0);
}

tree::TerminalNode* scqParser::ProcDefinitionContext::COMMA() {
  return getToken(scqParser::COMMA, 0);
}

scqParser::ProcBodyContext* scqParser::ProcDefinitionContext::procBody() {
  return getRuleContext<scqParser::ProcBodyContext>(0);
}

tree::TerminalNode* scqParser::ProcDefinitionContext::SEMICOLON() {
  return getToken(scqParser::SEMICOLON, 0);
}

tree::TerminalNode* scqParser::ProcDefinitionContext::PROCEDURE_TYPE() {
  return getToken(scqParser::PROCEDURE_TYPE, 0);
}

tree::TerminalNode* scqParser::ProcDefinitionContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}


size_t scqParser::ProcDefinitionContext::getRuleIndex() const {
  return scqParser::RuleProcDefinition;
}


scqParser::ProcDefinitionContext* scqParser::procDefinition() {
  ProcDefinitionContext *_localctx = _tracker.createInstance<ProcDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 4, scqParser::RuleProcDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scqParser::PROCEDURE_TYPE) {
      setState(58);
      match(scqParser::PROCEDURE_TYPE);
      setState(59);
      match(scqParser::EDGE_OP);
    }
    setState(62);
    match(scqParser::NAME);
    setState(63);
    match(scqParser::ASSIGN_OP);
    setState(64);
    procParams();
    setState(65);
    match(scqParser::COMMA);
    setState(66);
    procBody();
    setState(67);
    match(scqParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcParamsContext ------------------------------------------------------------------

scqParser::ProcParamsContext::ProcParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::ProcParamsContext::LEFT_CURL_BRACKET() {
  return getToken(scqParser::LEFT_CURL_BRACKET, 0);
}

tree::TerminalNode* scqParser::ProcParamsContext::RIGHT_CURL_BRACKET() {
  return getToken(scqParser::RIGHT_CURL_BRACKET, 0);
}

std::vector<tree::TerminalNode *> scqParser::ProcParamsContext::OBJECT_TYPE() {
  return getTokens(scqParser::OBJECT_TYPE);
}

tree::TerminalNode* scqParser::ProcParamsContext::OBJECT_TYPE(size_t i) {
  return getToken(scqParser::OBJECT_TYPE, i);
}

std::vector<tree::TerminalNode *> scqParser::ProcParamsContext::EDGE_OP() {
  return getTokens(scqParser::EDGE_OP);
}

tree::TerminalNode* scqParser::ProcParamsContext::EDGE_OP(size_t i) {
  return getToken(scqParser::EDGE_OP, i);
}

std::vector<tree::TerminalNode *> scqParser::ProcParamsContext::NAME() {
  return getTokens(scqParser::NAME);
}

tree::TerminalNode* scqParser::ProcParamsContext::NAME(size_t i) {
  return getToken(scqParser::NAME, i);
}

std::vector<tree::TerminalNode *> scqParser::ProcParamsContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::ProcParamsContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::ProcParamsContext::getRuleIndex() const {
  return scqParser::RuleProcParams;
}


scqParser::ProcParamsContext* scqParser::procParams() {
  ProcParamsContext *_localctx = _tracker.createInstance<ProcParamsContext>(_ctx, getState());
  enterRule(_localctx, 6, scqParser::RuleProcParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(scqParser::LEFT_CURL_BRACKET);
    setState(75);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::OBJECT_TYPE) {
      setState(70);
      match(scqParser::OBJECT_TYPE);
      setState(71);
      match(scqParser::EDGE_OP);
      setState(72);
      match(scqParser::NAME);
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(78);
      match(scqParser::COMMA);
      setState(83);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == scqParser::OBJECT_TYPE) {
        setState(79);
        match(scqParser::OBJECT_TYPE);
        setState(80);
        match(scqParser::EDGE_OP);
        setState(85);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(86);
      match(scqParser::NAME);
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(92);
    match(scqParser::RIGHT_CURL_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcBodyContext ------------------------------------------------------------------

scqParser::ProcBodyContext::ProcBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scqParser::ObjectCreationContext *> scqParser::ProcBodyContext::objectCreation() {
  return getRuleContexts<scqParser::ObjectCreationContext>();
}

scqParser::ObjectCreationContext* scqParser::ProcBodyContext::objectCreation(size_t i) {
  return getRuleContext<scqParser::ObjectCreationContext>(i);
}

std::vector<scqParser::CommandContext *> scqParser::ProcBodyContext::command() {
  return getRuleContexts<scqParser::CommandContext>();
}

scqParser::CommandContext* scqParser::ProcBodyContext::command(size_t i) {
  return getRuleContext<scqParser::CommandContext>(i);
}


size_t scqParser::ProcBodyContext::getRuleIndex() const {
  return scqParser::RuleProcBody;
}


scqParser::ProcBodyContext* scqParser::procBody() {
  ProcBodyContext *_localctx = _tracker.createInstance<ProcBodyContext>(_ctx, getState());
  enterRule(_localctx, 8, scqParser::RuleProcBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::COMMAND)
      | (1ULL << scqParser::OBJECT_TYPE)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(96);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case scqParser::OBJECT_TYPE:
        case scqParser::NAME: {
          setState(94);
          objectCreation();
          break;
        }

        case scqParser::COMMAND: {
          setState(95);
          command();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectCreationContext ------------------------------------------------------------------

scqParser::ObjectCreationContext::ObjectCreationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scqParser::ObjectCreationOperandContext *> scqParser::ObjectCreationContext::objectCreationOperand() {
  return getRuleContexts<scqParser::ObjectCreationOperandContext>();
}

scqParser::ObjectCreationOperandContext* scqParser::ObjectCreationContext::objectCreationOperand(size_t i) {
  return getRuleContext<scqParser::ObjectCreationOperandContext>(i);
}

std::vector<scqParser::CompositeOperandContext *> scqParser::ObjectCreationContext::compositeOperand() {
  return getRuleContexts<scqParser::CompositeOperandContext>();
}

scqParser::CompositeOperandContext* scqParser::ObjectCreationContext::compositeOperand(size_t i) {
  return getRuleContext<scqParser::CompositeOperandContext>(i);
}

tree::TerminalNode* scqParser::ObjectCreationContext::SEMICOLON() {
  return getToken(scqParser::SEMICOLON, 0);
}

tree::TerminalNode* scqParser::ObjectCreationContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}

std::vector<tree::TerminalNode *> scqParser::ObjectCreationContext::ASSIGN_OP() {
  return getTokens(scqParser::ASSIGN_OP);
}

tree::TerminalNode* scqParser::ObjectCreationContext::ASSIGN_OP(size_t i) {
  return getToken(scqParser::ASSIGN_OP, i);
}

std::vector<tree::TerminalNode *> scqParser::ObjectCreationContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::ObjectCreationContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::ObjectCreationContext::getRuleIndex() const {
  return scqParser::RuleObjectCreation;
}


scqParser::ObjectCreationContext* scqParser::objectCreation() {
  ObjectCreationContext *_localctx = _tracker.createInstance<ObjectCreationContext>(_ctx, getState());
  enterRule(_localctx, 10, scqParser::RuleObjectCreation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    objectCreationOperand();
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(102);
      match(scqParser::COMMA);
      setState(103);
      objectCreationOperand();
      setState(108);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(109);
    _la = _input->LA(1);
    if (!(_la == scqParser::EDGE_OP

    || _la == scqParser::ASSIGN_OP)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(110);
    compositeOperand();
    setState(115);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::ASSIGN_OP) {
      setState(111);
      match(scqParser::ASSIGN_OP);
      setState(112);
      compositeOperand();
      setState(117);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(118);
    match(scqParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectCreationOperandContext ------------------------------------------------------------------

scqParser::ObjectCreationOperandContext::ObjectCreationOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::ObjectCreationOperandContext::NAME() {
  return getToken(scqParser::NAME, 0);
}

tree::TerminalNode* scqParser::ObjectCreationOperandContext::OBJECT_TYPE() {
  return getToken(scqParser::OBJECT_TYPE, 0);
}


size_t scqParser::ObjectCreationOperandContext::getRuleIndex() const {
  return scqParser::RuleObjectCreationOperand;
}


scqParser::ObjectCreationOperandContext* scqParser::objectCreationOperand() {
  ObjectCreationOperandContext *_localctx = _tracker.createInstance<ObjectCreationOperandContext>(_ctx, getState());
  enterRule(_localctx, 12, scqParser::RuleObjectCreationOperand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(120);
    _la = _input->LA(1);
    if (!(_la == scqParser::OBJECT_TYPE

    || _la == scqParser::NAME)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandContext ------------------------------------------------------------------

scqParser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::CommandContext::COMMAND() {
  return getToken(scqParser::COMMAND, 0);
}

tree::TerminalNode* scqParser::CommandContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}

std::vector<scqParser::CommandCompositeOperandContext *> scqParser::CommandContext::commandCompositeOperand() {
  return getRuleContexts<scqParser::CommandCompositeOperandContext>();
}

scqParser::CommandCompositeOperandContext* scqParser::CommandContext::commandCompositeOperand(size_t i) {
  return getRuleContext<scqParser::CommandCompositeOperandContext>(i);
}

tree::TerminalNode* scqParser::CommandContext::SEMICOLON() {
  return getToken(scqParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> scqParser::CommandContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::CommandContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::CommandContext::getRuleIndex() const {
  return scqParser::RuleCommand;
}


scqParser::CommandContext* scqParser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 14, scqParser::RuleCommand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(scqParser::COMMAND);
    setState(123);
    match(scqParser::EDGE_OP);
    setState(124);
    commandCompositeOperand();
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(125);
      match(scqParser::COMMA);
      setState(126);
      commandCompositeOperand();
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(132);
    match(scqParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompositeOperandContext ------------------------------------------------------------------

scqParser::CompositeOperandContext::CompositeOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scqParser::OperandContext *> scqParser::CompositeOperandContext::operand() {
  return getRuleContexts<scqParser::OperandContext>();
}

scqParser::OperandContext* scqParser::CompositeOperandContext::operand(size_t i) {
  return getRuleContext<scqParser::OperandContext>(i);
}

std::vector<tree::TerminalNode *> scqParser::CompositeOperandContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::CompositeOperandContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::CompositeOperandContext::getRuleIndex() const {
  return scqParser::RuleCompositeOperand;
}


scqParser::CompositeOperandContext* scqParser::compositeOperand() {
  CompositeOperandContext *_localctx = _tracker.createInstance<CompositeOperandContext>(_ctx, getState());
  enterRule(_localctx, 16, scqParser::RuleCompositeOperand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(134);
    operand();
    setState(139);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(135);
        match(scqParser::COMMA);
        setState(136);
        operand(); 
      }
      setState(141);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandCompositeOperandContext ------------------------------------------------------------------

scqParser::CommandCompositeOperandContext::CommandCompositeOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::CommandCompositeOperandContext::NAME() {
  return getToken(scqParser::NAME, 0);
}

tree::TerminalNode* scqParser::CommandCompositeOperandContext::STRING() {
  return getToken(scqParser::STRING, 0);
}

scqParser::OrientedSetContext* scqParser::CommandCompositeOperandContext::orientedSet() {
  return getRuleContext<scqParser::OrientedSetContext>(0);
}

scqParser::TemplateCommandContext* scqParser::CommandCompositeOperandContext::templateCommand() {
  return getRuleContext<scqParser::TemplateCommandContext>(0);
}


size_t scqParser::CommandCompositeOperandContext::getRuleIndex() const {
  return scqParser::RuleCommandCompositeOperand;
}


scqParser::CommandCompositeOperandContext* scqParser::commandCompositeOperand() {
  CommandCompositeOperandContext *_localctx = _tracker.createInstance<CommandCompositeOperandContext>(_ctx, getState());
  enterRule(_localctx, 18, scqParser::RuleCommandCompositeOperand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(146);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(142);
        match(scqParser::NAME);
        break;
      }

      case scqParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(143);
        match(scqParser::STRING);
        break;
      }

      case scqParser::LEFT_CURL_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(144);
        orientedSet();
        break;
      }

      case scqParser::LEFT_SQUARE_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(145);
        templateCommand();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandContext ------------------------------------------------------------------

scqParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::OperandContext::NAME() {
  return getToken(scqParser::NAME, 0);
}

tree::TerminalNode* scqParser::OperandContext::STRING() {
  return getToken(scqParser::STRING, 0);
}

scqParser::OrientedSetContext* scqParser::OperandContext::orientedSet() {
  return getRuleContext<scqParser::OrientedSetContext>(0);
}

scqParser::NonOrientedSetContext* scqParser::OperandContext::nonOrientedSet() {
  return getRuleContext<scqParser::NonOrientedSetContext>(0);
}

scqParser::TemplateCommandContext* scqParser::OperandContext::templateCommand() {
  return getRuleContext<scqParser::TemplateCommandContext>(0);
}


size_t scqParser::OperandContext::getRuleIndex() const {
  return scqParser::RuleOperand;
}


scqParser::OperandContext* scqParser::operand() {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState());
  enterRule(_localctx, 20, scqParser::RuleOperand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(148);
        match(scqParser::NAME);
        break;
      }

      case scqParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(149);
        match(scqParser::STRING);
        break;
      }

      case scqParser::LEFT_CURL_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(150);
        orientedSet();
        break;
      }

      case scqParser::LEFT_FIGURE_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(151);
        nonOrientedSet();
        break;
      }

      case scqParser::LEFT_SQUARE_BRACKET: {
        enterOuterAlt(_localctx, 5);
        setState(152);
        templateCommand();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonOrientedSetContext ------------------------------------------------------------------

scqParser::NonOrientedSetContext::NonOrientedSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::NonOrientedSetContext::LEFT_FIGURE_BRACKET() {
  return getToken(scqParser::LEFT_FIGURE_BRACKET, 0);
}

tree::TerminalNode* scqParser::NonOrientedSetContext::RIGHT_FIGURE_BRACKET() {
  return getToken(scqParser::RIGHT_FIGURE_BRACKET, 0);
}

std::vector<scqParser::CompositeOperandContext *> scqParser::NonOrientedSetContext::compositeOperand() {
  return getRuleContexts<scqParser::CompositeOperandContext>();
}

scqParser::CompositeOperandContext* scqParser::NonOrientedSetContext::compositeOperand(size_t i) {
  return getRuleContext<scqParser::CompositeOperandContext>(i);
}

std::vector<tree::TerminalNode *> scqParser::NonOrientedSetContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::NonOrientedSetContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::NonOrientedSetContext::getRuleIndex() const {
  return scqParser::RuleNonOrientedSet;
}


scqParser::NonOrientedSetContext* scqParser::nonOrientedSet() {
  NonOrientedSetContext *_localctx = _tracker.createInstance<NonOrientedSetContext>(_ctx, getState());
  enterRule(_localctx, 22, scqParser::RuleNonOrientedSet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(scqParser::LEFT_FIGURE_BRACKET);
    setState(159);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::LEFT_SQUARE_BRACKET)
      | (1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::STRING)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(156);
      compositeOperand();
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(166);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(162);
      match(scqParser::COMMA);
      setState(163);
      compositeOperand();
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169);
    match(scqParser::RIGHT_FIGURE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrientedSetContext ------------------------------------------------------------------

scqParser::OrientedSetContext::OrientedSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::OrientedSetContext::LEFT_CURL_BRACKET() {
  return getToken(scqParser::LEFT_CURL_BRACKET, 0);
}

tree::TerminalNode* scqParser::OrientedSetContext::RIGHT_CURL_BRACKET() {
  return getToken(scqParser::RIGHT_CURL_BRACKET, 0);
}

std::vector<scqParser::CompositeOperandContext *> scqParser::OrientedSetContext::compositeOperand() {
  return getRuleContexts<scqParser::CompositeOperandContext>();
}

scqParser::CompositeOperandContext* scqParser::OrientedSetContext::compositeOperand(size_t i) {
  return getRuleContext<scqParser::CompositeOperandContext>(i);
}

std::vector<tree::TerminalNode *> scqParser::OrientedSetContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::OrientedSetContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::OrientedSetContext::getRuleIndex() const {
  return scqParser::RuleOrientedSet;
}


scqParser::OrientedSetContext* scqParser::orientedSet() {
  OrientedSetContext *_localctx = _tracker.createInstance<OrientedSetContext>(_ctx, getState());
  enterRule(_localctx, 24, scqParser::RuleOrientedSet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(scqParser::LEFT_CURL_BRACKET);
    setState(175);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::LEFT_SQUARE_BRACKET)
      | (1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::STRING)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(172);
      compositeOperand();
      setState(177);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(182);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(178);
      match(scqParser::COMMA);
      setState(179);
      compositeOperand();
      setState(184);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(185);
    match(scqParser::RIGHT_CURL_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemplateCommandContext ------------------------------------------------------------------

scqParser::TemplateCommandContext::TemplateCommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scqParser::TemplateExpressionContext *> scqParser::TemplateCommandContext::templateExpression() {
  return getRuleContexts<scqParser::TemplateExpressionContext>();
}

scqParser::TemplateExpressionContext* scqParser::TemplateCommandContext::templateExpression(size_t i) {
  return getRuleContext<scqParser::TemplateExpressionContext>(i);
}

std::vector<tree::TerminalNode *> scqParser::TemplateCommandContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::TemplateCommandContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}

scqParser::CommandTemplateResultContext* scqParser::TemplateCommandContext::commandTemplateResult() {
  return getRuleContext<scqParser::CommandTemplateResultContext>(0);
}


size_t scqParser::TemplateCommandContext::getRuleIndex() const {
  return scqParser::RuleTemplateCommand;
}


scqParser::TemplateCommandContext* scqParser::templateCommand() {
  TemplateCommandContext *_localctx = _tracker.createInstance<TemplateCommandContext>(_ctx, getState());
  enterRule(_localctx, 26, scqParser::RuleTemplateCommand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(187);
    templateExpression();
    setState(192);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(188);
        match(scqParser::COMMA);
        setState(189);
        templateExpression(); 
      }
      setState(194);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
    setState(196);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scqParser::AS_OP) {
      setState(195);
      commandTemplateResult();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemplateExpressionContext ------------------------------------------------------------------

scqParser::TemplateExpressionContext::TemplateExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::TemplateExpressionContext::LEFT_SQUARE_BRACKET() {
  return getToken(scqParser::LEFT_SQUARE_BRACKET, 0);
}

scqParser::CommandTemplateContext* scqParser::TemplateExpressionContext::commandTemplate() {
  return getRuleContext<scqParser::CommandTemplateContext>(0);
}

tree::TerminalNode* scqParser::TemplateExpressionContext::RIGHT_SQUARE_BRACKET() {
  return getToken(scqParser::RIGHT_SQUARE_BRACKET, 0);
}


size_t scqParser::TemplateExpressionContext::getRuleIndex() const {
  return scqParser::RuleTemplateExpression;
}


scqParser::TemplateExpressionContext* scqParser::templateExpression() {
  TemplateExpressionContext *_localctx = _tracker.createInstance<TemplateExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, scqParser::RuleTemplateExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(scqParser::LEFT_SQUARE_BRACKET);
    setState(199);
    commandTemplate();
    setState(200);
    match(scqParser::RIGHT_SQUARE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandTemplateContext ------------------------------------------------------------------

scqParser::CommandTemplateContext::CommandTemplateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scqParser::TemplateParamContext *> scqParser::CommandTemplateContext::templateParam() {
  return getRuleContexts<scqParser::TemplateParamContext>();
}

scqParser::TemplateParamContext* scqParser::CommandTemplateContext::templateParam(size_t i) {
  return getRuleContext<scqParser::TemplateParamContext>(i);
}

tree::TerminalNode* scqParser::CommandTemplateContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}

std::vector<tree::TerminalNode *> scqParser::CommandTemplateContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::CommandTemplateContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::CommandTemplateContext::getRuleIndex() const {
  return scqParser::RuleCommandTemplate;
}


scqParser::CommandTemplateContext* scqParser::commandTemplate() {
  CommandTemplateContext *_localctx = _tracker.createInstance<CommandTemplateContext>(_ctx, getState());
  enterRule(_localctx, 30, scqParser::RuleCommandTemplate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    templateParam();
    setState(207);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(203);
      match(scqParser::COMMA);
      setState(204);
      templateParam();
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(210);
    match(scqParser::EDGE_OP);
    setState(211);
    templateParam();
    setState(216);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(212);
      match(scqParser::COMMA);
      setState(213);
      templateParam();
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandTemplateResultContext ------------------------------------------------------------------

scqParser::CommandTemplateResultContext::CommandTemplateResultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::CommandTemplateResultContext::AS_OP() {
  return getToken(scqParser::AS_OP, 0);
}

tree::TerminalNode* scqParser::CommandTemplateResultContext::LEFT_SQUARE_BRACKET() {
  return getToken(scqParser::LEFT_SQUARE_BRACKET, 0);
}

std::vector<scqParser::TemplateParamContext *> scqParser::CommandTemplateResultContext::templateParam() {
  return getRuleContexts<scqParser::TemplateParamContext>();
}

scqParser::TemplateParamContext* scqParser::CommandTemplateResultContext::templateParam(size_t i) {
  return getRuleContext<scqParser::TemplateParamContext>(i);
}

tree::TerminalNode* scqParser::CommandTemplateResultContext::RIGHT_SQUARE_BRACKET() {
  return getToken(scqParser::RIGHT_SQUARE_BRACKET, 0);
}

std::vector<tree::TerminalNode *> scqParser::CommandTemplateResultContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::CommandTemplateResultContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::CommandTemplateResultContext::getRuleIndex() const {
  return scqParser::RuleCommandTemplateResult;
}


scqParser::CommandTemplateResultContext* scqParser::commandTemplateResult() {
  CommandTemplateResultContext *_localctx = _tracker.createInstance<CommandTemplateResultContext>(_ctx, getState());
  enterRule(_localctx, 32, scqParser::RuleCommandTemplateResult);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(scqParser::AS_OP);
    setState(220);
    match(scqParser::LEFT_SQUARE_BRACKET);
    setState(221);
    templateParam();
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(222);
      match(scqParser::COMMA);
      setState(223);
      templateParam();
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(229);
    match(scqParser::RIGHT_SQUARE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemplateParamContext ------------------------------------------------------------------

scqParser::TemplateParamContext::TemplateParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scqParser::TemplateParamContext::COMMAND() {
  return getToken(scqParser::COMMAND, 0);
}

tree::TerminalNode* scqParser::TemplateParamContext::OBJECT_TYPE() {
  return getToken(scqParser::OBJECT_TYPE, 0);
}

tree::TerminalNode* scqParser::TemplateParamContext::NAME() {
  return getToken(scqParser::NAME, 0);
}

tree::TerminalNode* scqParser::TemplateParamContext::LEFT_TRIANGLE_BRACKET() {
  return getToken(scqParser::LEFT_TRIANGLE_BRACKET, 0);
}

tree::TerminalNode* scqParser::TemplateParamContext::RIGHT_TRIANGLE_BRACKET() {
  return getToken(scqParser::RIGHT_TRIANGLE_BRACKET, 0);
}


size_t scqParser::TemplateParamContext::getRuleIndex() const {
  return scqParser::RuleTemplateParam;
}


scqParser::TemplateParamContext* scqParser::templateParam() {
  TemplateParamContext *_localctx = _tracker.createInstance<TemplateParamContext>(_ctx, getState());
  enterRule(_localctx, 34, scqParser::RuleTemplateParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(237);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::COMMAND: {
        enterOuterAlt(_localctx, 1);
        setState(231);
        match(scqParser::COMMAND);
        break;
      }

      case scqParser::OBJECT_TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(232);
        match(scqParser::OBJECT_TYPE);
        break;
      }

      case scqParser::NAME: {
        enterOuterAlt(_localctx, 3);
        setState(233);
        match(scqParser::NAME);
        break;
      }

      case scqParser::LEFT_TRIANGLE_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(234);
        match(scqParser::LEFT_TRIANGLE_BRACKET);
        setState(235);
        match(scqParser::NAME);
        setState(236);
        match(scqParser::RIGHT_TRIANGLE_BRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> scqParser::_decisionToDFA;
atn::PredictionContextCache scqParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN scqParser::_atn;
std::vector<uint16_t> scqParser::_serializedATN;

std::vector<std::string> scqParser::_ruleNames = {
  "program", "procDeclaration", "procDefinition", "procParams", "procBody", 
  "objectCreation", "objectCreationOperand", "command", "compositeOperand", 
  "commandCompositeOperand", "operand", "nonOrientedSet", "orientedSet", 
  "templateCommand", "templateExpression", "commandTemplate", "commandTemplateResult", 
  "templateParam"
};

std::vector<std::string> scqParser::_literalNames = {
  "", "'->'", "':='", "'as'", "'<'", "'>'", "'['", "']'", "'{'", "'}'", 
  "'('", "')'", "','", "';'", "", "'procedure'"
};

std::vector<std::string> scqParser::_symbolicNames = {
  "", "EDGE_OP", "ASSIGN_OP", "AS_OP", "LEFT_TRIANGLE_BRACKET", "RIGHT_TRIANGLE_BRACKET", 
  "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "LEFT_FIGURE_BRACKET", 
  "RIGHT_FIGURE_BRACKET", "LEFT_CURL_BRACKET", "RIGHT_CURL_BRACKET", "COMMA", 
  "SEMICOLON", "COMMAND", "PROCEDURE_TYPE", "OBJECT_TYPE", "STRING", "NAME", 
  "LETTER", "DIGIT", "WS", "SL_COMMENT"
};

dfa::Vocabulary scqParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> scqParser::_tokenNames;

scqParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x18, 0xf2, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x3, 0x2, 0x6, 0x2, 0x28, 0xa, 0x2, 
    0xd, 0x2, 0xe, 0x2, 0x29, 0x3, 0x2, 0x6, 0x2, 0x2d, 0xa, 0x2, 0xd, 0x2, 
    0xe, 0x2, 0x2e, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x36, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x39, 0xb, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x3f, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x4c, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x4f, 
    0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x54, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x57, 0xb, 0x5, 0x3, 0x5, 0x7, 0x5, 0x5a, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x5d, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0x63, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x66, 0xb, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x6b, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x6e, 
    0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x74, 0xa, 
    0x7, 0xc, 0x7, 0xe, 0x7, 0x77, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 
    0x82, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x85, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x8c, 0xa, 0xa, 0xc, 0xa, 0xe, 
    0xa, 0x8f, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x95, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0x9c, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xa0, 0xa, 0xd, 0xc, 
    0xd, 0xe, 0xd, 0xa3, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xa7, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0xaa, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x7, 0xe, 0xb0, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xb3, 0xb, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xb7, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xba, 
    0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 
    0xc1, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xc4, 0xb, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0xc7, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0xd0, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 
    0xd3, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 
    0xd9, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xdc, 0xb, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0xe3, 0xa, 0x12, 0xc, 
    0x12, 0xe, 0x12, 0xe6, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xf0, 0xa, 
    0x13, 0x3, 0x13, 0x2, 0x2, 0x14, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x2, 
    0x4, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x12, 0x12, 0x14, 0x14, 0x2, 0xff, 
    0x2, 0x27, 0x3, 0x2, 0x2, 0x2, 0x4, 0x30, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3e, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x47, 0x3, 0x2, 0x2, 0x2, 0xa, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x67, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7a, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x12, 0x88, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x16, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xad, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x20, 0xcc, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x24, 0xef, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x28, 0x5, 0x4, 0x3, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2d, 
    0x5, 0x6, 0x4, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x11, 0x2, 
    0x2, 0x31, 0x32, 0x7, 0x3, 0x2, 0x2, 0x32, 0x37, 0x7, 0x14, 0x2, 0x2, 
    0x33, 0x34, 0x7, 0xe, 0x2, 0x2, 0x34, 0x36, 0x7, 0x14, 0x2, 0x2, 0x35, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0xf, 
    0x2, 0x2, 0x3b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x11, 0x2, 
    0x2, 0x3d, 0x3f, 0x7, 0x3, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x41, 0x7, 0x14, 0x2, 0x2, 0x41, 0x42, 0x7, 0x4, 0x2, 0x2, 0x42, 0x43, 
    0x5, 0x8, 0x5, 0x2, 0x43, 0x44, 0x7, 0xe, 0x2, 0x2, 0x44, 0x45, 0x5, 
    0xa, 0x6, 0x2, 0x45, 0x46, 0x7, 0xf, 0x2, 0x2, 0x46, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x47, 0x4d, 0x7, 0xc, 0x2, 0x2, 0x48, 0x49, 0x7, 0x12, 0x2, 
    0x2, 0x49, 0x4a, 0x7, 0x3, 0x2, 0x2, 0x4a, 0x4c, 0x7, 0x14, 0x2, 0x2, 
    0x4b, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x5b, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x55, 0x7, 
    0xe, 0x2, 0x2, 0x51, 0x52, 0x7, 0x12, 0x2, 0x2, 0x52, 0x54, 0x7, 0x3, 
    0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x58, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x5a, 0x7, 0x14, 0x2, 0x2, 0x59, 0x50, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x5f, 0x7, 0xd, 0x2, 0x2, 0x5f, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x63, 0x5, 0xc, 0x7, 0x2, 0x61, 0x63, 0x5, 0x10, 0x9, 0x2, 
    0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0xb, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x6c, 0x5, 0xe, 0x8, 0x2, 0x68, 0x69, 0x7, 0xe, 
    0x2, 0x2, 0x69, 0x6b, 0x5, 0xe, 0x8, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x9, 0x2, 0x2, 0x2, 0x70, 0x75, 
    0x5, 0x12, 0xa, 0x2, 0x71, 0x72, 0x7, 0x4, 0x2, 0x2, 0x72, 0x74, 0x5, 
    0x12, 0xa, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x74, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x78, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x79, 0x7, 0xf, 0x2, 0x2, 0x79, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x7b, 0x9, 0x3, 0x2, 0x2, 0x7b, 0xf, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 
    0x7, 0x10, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x3, 0x2, 0x2, 0x7e, 0x83, 0x5, 
    0x14, 0xb, 0x2, 0x7f, 0x80, 0x7, 0xe, 0x2, 0x2, 0x80, 0x82, 0x5, 0x14, 
    0xb, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x86, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x87, 0x7, 0xf, 0x2, 0x2, 0x87, 0x11, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8d, 
    0x5, 0x16, 0xc, 0x2, 0x89, 0x8a, 0x7, 0xe, 0x2, 0x2, 0x8a, 0x8c, 0x5, 
    0x16, 0xc, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x95, 0x7, 0x14, 0x2, 0x2, 0x91, 0x95, 0x7, 0x13, 0x2, 0x2, 0x92, 
    0x95, 0x5, 0x1a, 0xe, 0x2, 0x93, 0x95, 0x5, 0x1c, 0xf, 0x2, 0x94, 0x90, 
    0x3, 0x2, 0x2, 0x2, 0x94, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x15, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x9c, 0x7, 0x14, 0x2, 0x2, 0x97, 0x9c, 0x7, 0x13, 0x2, 
    0x2, 0x98, 0x9c, 0x5, 0x1a, 0xe, 0x2, 0x99, 0x9c, 0x5, 0x18, 0xd, 0x2, 
    0x9a, 0x9c, 0x5, 0x1c, 0xf, 0x2, 0x9b, 0x96, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0xa1, 0x7, 0xa, 0x2, 0x2, 0x9e, 0xa0, 0x5, 0x12, 
    0xa, 0x2, 0x9f, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa5, 0x7, 0xe, 0x2, 0x2, 0xa5, 0xa7, 0x5, 0x12, 0xa, 0x2, 0xa6, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 
    0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0xb, 0x2, 
    0x2, 0xac, 0x19, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb1, 0x7, 0xc, 0x2, 0x2, 
    0xae, 0xb0, 0x5, 0x12, 0xa, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0xe, 0x2, 0x2, 0xb5, 0xb7, 0x5, 0x12, 
    0xa, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xbc, 0x7, 0xd, 0x2, 0x2, 0xbc, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xc2, 
    0x5, 0x1e, 0x10, 0x2, 0xbe, 0xbf, 0x7, 0xe, 0x2, 0x2, 0xbf, 0xc1, 0x5, 
    0x1e, 0x10, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0xc7, 0x5, 0x22, 0x12, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 
    0x7, 0x8, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x20, 0x11, 0x2, 0xca, 0xcb, 0x7, 
    0x9, 0x2, 0x2, 0xcb, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xd1, 0x5, 0x24, 
    0x13, 0x2, 0xcd, 0xce, 0x7, 0xe, 0x2, 0x2, 0xce, 0xd0, 0x5, 0x24, 0x13, 
    0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 
    0x7, 0x3, 0x2, 0x2, 0xd5, 0xda, 0x5, 0x24, 0x13, 0x2, 0xd6, 0xd7, 0x7, 
    0xe, 0x2, 0x2, 0xd7, 0xd9, 0x5, 0x24, 0x13, 0x2, 0xd8, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x5, 0x2, 0x2, 0xde, 
    0xdf, 0x7, 0x8, 0x2, 0x2, 0xdf, 0xe4, 0x5, 0x24, 0x13, 0x2, 0xe0, 0xe1, 
    0x7, 0xe, 0x2, 0x2, 0xe1, 0xe3, 0x5, 0x24, 0x13, 0x2, 0xe2, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe7, 0x3, 0x2, 0x2, 
    0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x7, 0x9, 0x2, 0x2, 
    0xe8, 0x23, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xf0, 0x7, 0x10, 0x2, 0x2, 0xea, 
    0xf0, 0x7, 0x12, 0x2, 0x2, 0xeb, 0xf0, 0x7, 0x14, 0x2, 0x2, 0xec, 0xed, 
    0x7, 0x6, 0x2, 0x2, 0xed, 0xee, 0x7, 0x14, 0x2, 0x2, 0xee, 0xf0, 0x7, 
    0x7, 0x2, 0x2, 0xef, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xef, 0xea, 0x3, 0x2, 
    0x2, 0x2, 0xef, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xef, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0xf0, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x29, 0x2e, 0x37, 0x3e, 0x4d, 
    0x55, 0x5b, 0x62, 0x64, 0x6c, 0x75, 0x83, 0x8d, 0x94, 0x9b, 0xa1, 0xa8, 
    0xb1, 0xb8, 0xc2, 0xc6, 0xd1, 0xda, 0xe4, 0xef, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

scqParser::Initializer scqParser::_init;
