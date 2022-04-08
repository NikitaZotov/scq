
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


// Generated from /home/nikita/CLionProjects/ostis-web-platform/sc-machine/scq/scq/scq.g4 by ANTLR 4.9.2


#include "scqListener.h"
#include "scqVisitor.h"

#include "scqParser.h"


using namespace antlrcpp;
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

scqParser::BlockContext* scqParser::ProgramContext::block() {
  return getRuleContext<scqParser::BlockContext>(0);
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

void scqParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void scqParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any scqParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

scqParser::ProgramContext* scqParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, scqParser::RuleProgram);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(41);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(38);
        procDeclaration(_localctx->procs); 
      }
      setState(43);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(47);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(44);
        procDefinition(_localctx->procs, _localctx->procDefs); 
      }
      setState(49);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(50);
    block(_localctx->procDefs, nullptr);
   
  }
  catch (utils::ScException const & e) {
    SC_LOG_ERROR("Parse error occurred: " + std::string(e.Message()));
  }
  return _localctx;
}

//----------------- ProcDeclarationContext ------------------------------------------------------------------

scqParser::ProcDeclarationContext::ProcDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::ProcDeclarationContext::ProcDeclarationContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Procedures * procs)
  : ParserRuleContext(parent, invokingState) {
  this->procs = procs;
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

void scqParser::ProcDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcDeclaration(this);
}

void scqParser::ProcDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcDeclaration(this);
}


antlrcpp::Any scqParser::ProcDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitProcDeclaration(this);
  else
    return visitor->visitChildren(this);
}

scqParser::ProcDeclarationContext* scqParser::procDeclaration(ProgramContext::Procedures * procs) {
  ProcDeclarationContext *_localctx = _tracker.createInstance<ProcDeclarationContext>(_ctx, getState(), procs);
  enterRule(_localctx, 2, scqParser::RuleProcDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    match(scqParser::PROCEDURE_TYPE);
    setState(53);
    match(scqParser::EDGE_OP);
    setState(54);
    dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken = match(scqParser::NAME);

    	if (_localctx->procs->find((dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "")) != _localctx->procs->end()) {
    	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + (dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" is declared.");
    	}
    	else {
    	  _localctx->procs->insert((dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : ""));
    	  SC_LOG_DEBUG("Declare \"" + (dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" procedure");
        }
    	
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(56);
      match(scqParser::COMMA);
      setState(57);
      dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken = match(scqParser::NAME);

          if (_localctx->procs->find((dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "")) != _localctx->procs->end()) {
            SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + (dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" is declared.");
          }
          else {
            _localctx->procs->insert((dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : ""));
            SC_LOG_DEBUG("Declare \"" + (dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" procedure");
          }
          
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(64);
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

scqParser::ProcDefinitionContext::ProcDefinitionContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Procedures * procs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->procs = procs;
  this->procDefs = procDefs;
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

scqParser::BlockContext* scqParser::ProcDefinitionContext::block() {
  return getRuleContext<scqParser::BlockContext>(0);
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

void scqParser::ProcDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcDefinition(this);
}

void scqParser::ProcDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcDefinition(this);
}


antlrcpp::Any scqParser::ProcDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitProcDefinition(this);
  else
    return visitor->visitChildren(this);
}

scqParser::ProcDefinitionContext* scqParser::procDefinition(ProgramContext::Procedures * procs,ProgramContext::ProcedureDefinitions * procDefs) {
  ProcDefinitionContext *_localctx = _tracker.createInstance<ProcDefinitionContext>(_ctx, getState(), procs, procDefs);
  enterRule(_localctx, 4, scqParser::RuleProcDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scqParser::PROCEDURE_TYPE) {
      setState(66);
      match(scqParser::PROCEDURE_TYPE);
      setState(67);
      match(scqParser::EDGE_OP);
    }
    setState(70);
    dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken = match(scqParser::NAME);

        if (_localctx->procs->find((dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken->getText() : "")) == _localctx->procs->end()) {
          SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + (dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken->getText() : "") + "\" isn't declared.");
        }
        
    setState(72);
    match(scqParser::ASSIGN_OP);
    setState(73);
    procParams(_localctx->params);
    setState(74);
    match(scqParser::COMMA);
    setState(75);
    block(_localctx->procDefs, _localctx->params);

     	_localctx->procDefs->insert({ (dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken->getText() : ""), _localctx->params });
        SC_LOG_DEBUG("Define \"" + (dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken->getText() : "") + "\" procedure");
     	
    setState(77);
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

scqParser::ProcParamsContext::ProcParamsContext(ParserRuleContext *parent, size_t invokingState, ProcDefinitionContext::ProcedureParams * params)
  : ParserRuleContext(parent, invokingState) {
  this->params = params;
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

void scqParser::ProcParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcParams(this);
}

void scqParser::ProcParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcParams(this);
}


antlrcpp::Any scqParser::ProcParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitProcParams(this);
  else
    return visitor->visitChildren(this);
}

scqParser::ProcParamsContext* scqParser::procParams(ProcDefinitionContext::ProcedureParams * params) {
  ProcParamsContext *_localctx = _tracker.createInstance<ProcParamsContext>(_ctx, getState(), params);
  enterRule(_localctx, 6, scqParser::RuleProcParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(scqParser::LEFT_CURL_BRACKET);
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::OBJECT_TYPE) {
      setState(80);
      dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken = match(scqParser::OBJECT_TYPE);
      setState(81);
      match(scqParser::EDGE_OP);
      setState(82);
      dynamic_cast<ProcParamsContext *>(_localctx)->nameToken = match(scqParser::NAME);

      	if (std::find_if(_localctx->params->begin(), _localctx->params->end(), [&](auto & item) -> bool { item.first == (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : ""); }) != _localctx->params->end()) {
            SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param \"" + (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : "") + "\" is repeated.");
          }
          else {
            _localctx->params->push_back({ (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : ""), (dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken->getText() : "") });
            SC_LOG_DEBUG("Define \"" + (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : "") + "\" param");
          }
      	
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(101);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(89);
      match(scqParser::COMMA);
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == scqParser::OBJECT_TYPE) {
        setState(90);
        dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken = match(scqParser::OBJECT_TYPE);
        setState(91);
        match(scqParser::EDGE_OP);
        setState(96);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(97);
      dynamic_cast<ProcParamsContext *>(_localctx)->nameToken = match(scqParser::NAME);

          if (std::find_if(_localctx->params->begin(), _localctx->params->end(), [&](auto & item) -> bool { item.first == (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : ""); }) != _localctx->params->end()) {
            SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param \"" + (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : "") + "\" is repeated.");
          }
          else {
            _localctx->params->push_back({ (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : ""), (dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken->getText() : "") });
            SC_LOG_DEBUG("Define \"" + (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : "") + "\" param");
          }
          
      setState(103);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(104);
    match(scqParser::RIGHT_CURL_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

scqParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::ProcedureDefinitions * procDefs, ProcDefinitionContext::ProcedureParams * params)
  : ParserRuleContext(parent, invokingState) {
  this->procDefs = procDefs;
  this->params = params;
}

std::vector<scqParser::ObjectDeclarationContext *> scqParser::BlockContext::objectDeclaration() {
  return getRuleContexts<scqParser::ObjectDeclarationContext>();
}

scqParser::ObjectDeclarationContext* scqParser::BlockContext::objectDeclaration(size_t i) {
  return getRuleContext<scqParser::ObjectDeclarationContext>(i);
}

std::vector<scqParser::ObjectDefinitionContext *> scqParser::BlockContext::objectDefinition() {
  return getRuleContexts<scqParser::ObjectDefinitionContext>();
}

scqParser::ObjectDefinitionContext* scqParser::BlockContext::objectDefinition(size_t i) {
  return getRuleContext<scqParser::ObjectDefinitionContext>(i);
}

std::vector<scqParser::OperationContext *> scqParser::BlockContext::operation() {
  return getRuleContexts<scqParser::OperationContext>();
}

scqParser::OperationContext* scqParser::BlockContext::operation(size_t i) {
  return getRuleContext<scqParser::OperationContext>(i);
}


size_t scqParser::BlockContext::getRuleIndex() const {
  return scqParser::RuleBlock;
}

void scqParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void scqParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any scqParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

scqParser::BlockContext* scqParser::block(ProgramContext::ProcedureDefinitions * procDefs,ProcDefinitionContext::ProcedureParams * params) {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState(), procDefs, params);
  enterRule(_localctx, 8, scqParser::RuleBlock);

      if (params != nullptr) {
        std::for_each(params->begin(), params->end(), [&](const auto & item) {
          _localctx->objects->insert(item);
        });
      }
      
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::T__0)
      | (1ULL << scqParser::T__1)
      | (1ULL << scqParser::T__2)
      | (1ULL << scqParser::T__3)
      | (1ULL << scqParser::T__4)
      | (1ULL << scqParser::T__5)
      | (1ULL << scqParser::T__6)
      | (1ULL << scqParser::T__7)
      | (1ULL << scqParser::IF_OP)
      | (1ULL << scqParser::LEFT_SQUARE_BRACKET)
      | (1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::OBJECT_TYPE)
      | (1ULL << scqParser::STRING)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(109);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(106);
        objectDeclaration(_localctx->objects, _localctx->procDefs);
        break;
      }

      case 2: {
        setState(107);
        objectDefinition(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
        break;
      }

      case 3: {
        setState(108);
        operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
        break;
      }

      default:
        break;
      }
      setState(113);
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

//----------------- ObjectDeclarationContext ------------------------------------------------------------------

scqParser::ObjectDeclarationContext::ObjectDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::ObjectDeclarationContext::ObjectDeclarationContext(ParserRuleContext *parent, size_t invokingState, BlockContext::Objects * objects, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->procDefs = procDefs;
}

std::vector<tree::TerminalNode *> scqParser::ObjectDeclarationContext::OBJECT_TYPE() {
  return getTokens(scqParser::OBJECT_TYPE);
}

tree::TerminalNode* scqParser::ObjectDeclarationContext::OBJECT_TYPE(size_t i) {
  return getToken(scqParser::OBJECT_TYPE, i);
}

tree::TerminalNode* scqParser::ObjectDeclarationContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}

std::vector<tree::TerminalNode *> scqParser::ObjectDeclarationContext::NAME() {
  return getTokens(scqParser::NAME);
}

tree::TerminalNode* scqParser::ObjectDeclarationContext::NAME(size_t i) {
  return getToken(scqParser::NAME, i);
}

tree::TerminalNode* scqParser::ObjectDeclarationContext::SEMICOLON() {
  return getToken(scqParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> scqParser::ObjectDeclarationContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::ObjectDeclarationContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::ObjectDeclarationContext::getRuleIndex() const {
  return scqParser::RuleObjectDeclaration;
}

void scqParser::ObjectDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectDeclaration(this);
}

void scqParser::ObjectDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectDeclaration(this);
}


antlrcpp::Any scqParser::ObjectDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitObjectDeclaration(this);
  else
    return visitor->visitChildren(this);
}

scqParser::ObjectDeclarationContext* scqParser::objectDeclaration(BlockContext::Objects * objects,ProgramContext::ProcedureDefinitions * procDefs) {
  ObjectDeclarationContext *_localctx = _tracker.createInstance<ObjectDeclarationContext>(_ctx, getState(), objects, procDefs);
  enterRule(_localctx, 10, scqParser::RuleObjectDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken = match(scqParser::OBJECT_TYPE);
    setState(123);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(115);
      match(scqParser::COMMA);
      setState(119);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case scqParser::OBJECT_TYPE: {
          setState(116);
          dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken = match(scqParser::OBJECT_TYPE);
          break;
        }

        case scqParser::NAME: {
          setState(117);
          dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken = match(scqParser::NAME);

              if (_localctx->objects->find((dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "")) == _localctx->objects->end()) {
                SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" isn't declared.");
              }
              
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(125);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(126);
    match(scqParser::EDGE_OP);
    setState(127);
    dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken = match(scqParser::NAME);

        if (_localctx->objects->find((dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "")) != _localctx->objects->end()) {
          SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" is declared.");
        }
        else {
          _localctx->objects->insert({ (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : ""), (dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken->getText() : "") });
          SC_LOG_DEBUG("Declare \"" + (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" object");
        }
        
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(129);
      match(scqParser::COMMA);
      setState(130);
      dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken = match(scqParser::NAME);

          if (_localctx->objects->find((dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "")) != _localctx->objects->end()) {
            SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" is declared.");
          }
          else {
            _localctx->objects->insert({ (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : ""), (dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken->getText() : "") });
            SC_LOG_DEBUG("Declare \"" + (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" object");
          }
          
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(137);
    match(scqParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectDefinitionContext ------------------------------------------------------------------

scqParser::ObjectDefinitionContext::ObjectDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::ObjectDefinitionContext::ObjectDefinitionContext(ParserRuleContext *parent, size_t invokingState, BlockContext::Objects * objects, BlockContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->procDefs = procDefs;
}

tree::TerminalNode* scqParser::ObjectDefinitionContext::SEMICOLON() {
  return getToken(scqParser::SEMICOLON, 0);
}

tree::TerminalNode* scqParser::ObjectDefinitionContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}

scqParser::CompositeOperandContext* scqParser::ObjectDefinitionContext::compositeOperand() {
  return getRuleContext<scqParser::CompositeOperandContext>(0);
}

scqParser::OperationContext* scqParser::ObjectDefinitionContext::operation() {
  return getRuleContext<scqParser::OperationContext>(0);
}

std::vector<tree::TerminalNode *> scqParser::ObjectDefinitionContext::OBJECT_TYPE() {
  return getTokens(scqParser::OBJECT_TYPE);
}

tree::TerminalNode* scqParser::ObjectDefinitionContext::OBJECT_TYPE(size_t i) {
  return getToken(scqParser::OBJECT_TYPE, i);
}

std::vector<tree::TerminalNode *> scqParser::ObjectDefinitionContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::ObjectDefinitionContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}

tree::TerminalNode* scqParser::ObjectDefinitionContext::ASSIGN_OP() {
  return getToken(scqParser::ASSIGN_OP, 0);
}

std::vector<tree::TerminalNode *> scqParser::ObjectDefinitionContext::NAME() {
  return getTokens(scqParser::NAME);
}

tree::TerminalNode* scqParser::ObjectDefinitionContext::NAME(size_t i) {
  return getToken(scqParser::NAME, i);
}


size_t scqParser::ObjectDefinitionContext::getRuleIndex() const {
  return scqParser::RuleObjectDefinition;
}

void scqParser::ObjectDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectDefinition(this);
}

void scqParser::ObjectDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectDefinition(this);
}


antlrcpp::Any scqParser::ObjectDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitObjectDefinition(this);
  else
    return visitor->visitChildren(this);
}

scqParser::ObjectDefinitionContext* scqParser::objectDefinition(BlockContext::Objects * objects,BlockContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  ObjectDefinitionContext *_localctx = _tracker.createInstance<ObjectDefinitionContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 12, scqParser::RuleObjectDefinition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(142);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case scqParser::OBJECT_TYPE: {
          setState(139);
          match(scqParser::OBJECT_TYPE);
          break;
        }

        case scqParser::NAME: {
          setState(140);
          dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 = match(scqParser::NAME);

          	auto const & it = _localctx->procDefs->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""));
          	if (it != _localctx->procDefs->end()) {
          	  dynamic_cast<ObjectDefinitionContext *>(_localctx)->funcParams =  *(*procDefs->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""))).second;
          	  SC_LOG_DEBUG("Define \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : "") + "\" function");
          	  _localctx->objDefs->push_back({ (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""), _localctx });
          	}
          	else if (_localctx->objects->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : "")) == _localctx->objects->end()) {
          	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : "") + "\" isn't declared.");
              }
          	else {
                SC_LOG_DEBUG("Define \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : "") + "\" object");
          	  _localctx->objDefs->push_back({ (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""), _localctx });
              }
              
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == scqParser::COMMA) {
        setState(144);
        match(scqParser::COMMA);
        setState(148);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case scqParser::OBJECT_TYPE: {
            setState(145);
            match(scqParser::OBJECT_TYPE);
            break;
          }

          case scqParser::NAME: {
            setState(146);
            dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2 = match(scqParser::NAME);

                if (_localctx->objects->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2->getText() : "")) == _localctx->objects->end()) {
                  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2->getText() : "") + "\" isn't declared.");
                }
                else {
                  SC_LOG_DEBUG("Define \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2->getText() : "") + "\" object");
                  _localctx->objDefs->push_back({ (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n2->getText() : ""), _localctx });
                }
               	
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(154);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(155);
      match(scqParser::EDGE_OP);
      setState(156);
      compositeOperand(_localctx->objects, &_localctx->paramNum, &_localctx->funcParams);

      	if (_localctx->paramNum > _localctx->funcParams.size()) {
      	  SC_THROW_EXCEPTION(
      	    utils::ExceptionInvalidParams,
      	    "Expected " + std::to_string(_localctx->funcParams.size()) + " params. Gotten " + std::to_string(_localctx->paramNum) + ".");
      	}
      	
      break;
    }

    case 2: {
      setState(167);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(163);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          setState(160);
          dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 = match(scqParser::NAME);

              if (_localctx->objects->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "")) == _localctx->objects->end()) {
                SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "") + "\" isn't declared.");
              }
              else {
                SC_LOG_DEBUG("Define \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "") + "\" object");
                _localctx->objDefs->push_back({ (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : ""), _localctx });
              }
              
          setState(162);
          match(scqParser::ASSIGN_OP);
          break;
        }

        default:
          break;
        }
        setState(165);
        compositeOperand(_localctx->objects, &_localctx->paramNum, &_localctx->funcParams);
        break;
      }

      case 2: {
        setState(166);
        operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
    setState(171);
    match(scqParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationContext ------------------------------------------------------------------

scqParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState, BlockContext::Objects * objects, BlockContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->procDefs = procDefs;
}

tree::TerminalNode* scqParser::OperationContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}

std::vector<scqParser::OperationOperandContext *> scqParser::OperationContext::operationOperand() {
  return getRuleContexts<scqParser::OperationOperandContext>();
}

scqParser::OperationOperandContext* scqParser::OperationContext::operationOperand(size_t i) {
  return getRuleContext<scqParser::OperationOperandContext>(i);
}

tree::TerminalNode* scqParser::OperationContext::SEMICOLON() {
  return getToken(scqParser::SEMICOLON, 0);
}

scqParser::SetOperationContext* scqParser::OperationContext::setOperation() {
  return getRuleContext<scqParser::SetOperationContext>(0);
}

std::vector<tree::TerminalNode *> scqParser::OperationContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::OperationContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}

tree::TerminalNode* scqParser::OperationContext::NAME() {
  return getToken(scqParser::NAME, 0);
}

tree::TerminalNode* scqParser::OperationContext::IF_OP() {
  return getToken(scqParser::IF_OP, 0);
}

std::vector<scqParser::OperationContext *> scqParser::OperationContext::operation() {
  return getRuleContexts<scqParser::OperationContext>();
}

scqParser::OperationContext* scqParser::OperationContext::operation(size_t i) {
  return getRuleContext<scqParser::OperationContext>(i);
}

std::vector<scqParser::ObjectDefinitionContext *> scqParser::OperationContext::objectDefinition() {
  return getRuleContexts<scqParser::ObjectDefinitionContext>();
}

scqParser::ObjectDefinitionContext* scqParser::OperationContext::objectDefinition(size_t i) {
  return getRuleContext<scqParser::ObjectDefinitionContext>(i);
}


size_t scqParser::OperationContext::getRuleIndex() const {
  return scqParser::RuleOperation;
}

void scqParser::OperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperation(this);
}

void scqParser::OperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperation(this);
}


antlrcpp::Any scqParser::OperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitOperation(this);
  else
    return visitor->visitChildren(this);
}

scqParser::OperationContext* scqParser::operation(BlockContext::Objects * objects,BlockContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 14, scqParser::RuleOperation);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(212);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::T__0:
      case scqParser::T__1:
      case scqParser::T__2:
      case scqParser::T__3:
      case scqParser::T__4:
      case scqParser::T__5:
      case scqParser::T__6:
      case scqParser::T__7:
      case scqParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(176);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case scqParser::T__0:
          case scqParser::T__1:
          case scqParser::T__2:
          case scqParser::T__3:
          case scqParser::T__4:
          case scqParser::T__5:
          case scqParser::T__6:
          case scqParser::T__7: {
            setState(173);
            dynamic_cast<OperationContext *>(_localctx)->setOperationContext = setOperation(&_localctx->paramTypes);
            break;
          }

          case scqParser::NAME: {
            setState(174);
            dynamic_cast<OperationContext *>(_localctx)->nameToken = match(scqParser::NAME);

             	if (_localctx->procDefs->find((dynamic_cast<OperationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->nameToken->getText() : "")) == _localctx->procDefs->end()) {
                  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure " + (dynamic_cast<OperationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->nameToken->getText() : "") + " isn't declared.");
                }
            	
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(178);
        match(scqParser::EDGE_OP);
        setState(179);
        operationOperand(_localctx->objects, &_localctx->paramNum, &_localctx->paramTypes);
        setState(184);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == scqParser::COMMA) {
          setState(180);
          match(scqParser::COMMA);
          setState(181);
          operationOperand(_localctx->objects, &_localctx->paramNum, &_localctx->paramTypes);
          setState(186);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }

            if (dynamic_cast<OperationContext *>(_localctx)->nameToken != nullptr) {
              SC_LOG_DEBUG("Define \"" + (dynamic_cast<OperationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->nameToken->getText() : "") + "\" operation");
              _localctx->objDefs->push_back({ (dynamic_cast<OperationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->nameToken->getText() : ""), dynamic_cast<ObjectDefinitionContext *>(_localctx->parent) });
            }
            else {
              SC_LOG_DEBUG("Define \"" + (dynamic_cast<OperationContext *>(_localctx)->setOperationContext != nullptr ? _input->getText(dynamic_cast<OperationContext *>(_localctx)->setOperationContext->start, dynamic_cast<OperationContext *>(_localctx)->setOperationContext->stop) : nullptr) + "\" operation");
              _localctx->objDefs->push_back({ (dynamic_cast<OperationContext *>(_localctx)->setOperationContext != nullptr ? _input->getText(dynamic_cast<OperationContext *>(_localctx)->setOperationContext->start, dynamic_cast<OperationContext *>(_localctx)->setOperationContext->stop) : nullptr), dynamic_cast<ObjectDefinitionContext *>(_localctx->parent) });
            }
            
        setState(188);
        match(scqParser::SEMICOLON);

            if (_localctx->paramNum > _localctx->paramTypes.size()) {
              SC_THROW_EXCEPTION(
                utils::ExceptionInvalidParams,
            	"Expected " + std::to_string(_localctx->paramTypes.size()) + " params. Gotten " + std::to_string(_localctx->paramNum) + ".");
            }
            
        break;
      }

      case scqParser::IF_OP: {
        enterOuterAlt(_localctx, 2);
        setState(191);
        dynamic_cast<OperationContext *>(_localctx)->if_opToken = match(scqParser::IF_OP);
        setState(192);
        match(scqParser::EDGE_OP);
        setState(193);
        operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
        setState(194);
        match(scqParser::COMMA);
        setState(197);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(195);
          operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
          break;
        }

        case 2: {
          setState(196);
          objectDefinition(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
          break;
        }

        default:
          break;
        }
        setState(206);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == scqParser::COMMA) {
          setState(199);
          match(scqParser::COMMA);
          setState(202);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
          case 1: {
            setState(200);
            operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
            break;
          }

          case 2: {
            setState(201);
            objectDefinition(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
            break;
          }

          default:
            break;
          }
          setState(208);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }

        	  SC_LOG_DEBUG("Define \"" + (dynamic_cast<OperationContext *>(_localctx)->if_opToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->if_opToken->getText() : "") + "\" operation");
              _localctx->objDefs->push_back({ (dynamic_cast<OperationContext *>(_localctx)->if_opToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->if_opToken->getText() : ""), dynamic_cast<ObjectDefinitionContext *>(_localctx->parent) });
        	
        setState(210);
        match(scqParser::SEMICOLON);
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

//----------------- CompositeOperandContext ------------------------------------------------------------------

scqParser::CompositeOperandContext::CompositeOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::CompositeOperandContext::CompositeOperandContext(ParserRuleContext *parent, size_t invokingState, BlockContext::Objects * objects, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->paramNum = paramNum;
  this->params = params;
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

void scqParser::CompositeOperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompositeOperand(this);
}

void scqParser::CompositeOperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompositeOperand(this);
}


antlrcpp::Any scqParser::CompositeOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitCompositeOperand(this);
  else
    return visitor->visitChildren(this);
}

scqParser::CompositeOperandContext* scqParser::compositeOperand(BlockContext::Objects * objects,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params) {
  CompositeOperandContext *_localctx = _tracker.createInstance<CompositeOperandContext>(_ctx, getState(), objects, paramNum, params);
  enterRule(_localctx, 16, scqParser::RuleCompositeOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(214);
    operand(_localctx->objects, _localctx->paramNum, _localctx->params);
    setState(219);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(215);
        match(scqParser::COMMA);
        setState(216);
        operand(_localctx->objects, _localctx->paramNum, _localctx->params); 
      }
      setState(221);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperationOperandContext ------------------------------------------------------------------

scqParser::OperationOperandContext::OperationOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::OperationOperandContext::OperationOperandContext(ParserRuleContext *parent, size_t invokingState, BlockContext::Objects * objects, size_t * paramNum, std::vector<std::vector<std::string>> * params)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->paramNum = paramNum;
  this->params = params;
}

tree::TerminalNode* scqParser::OperationOperandContext::NAME() {
  return getToken(scqParser::NAME, 0);
}

tree::TerminalNode* scqParser::OperationOperandContext::STRING() {
  return getToken(scqParser::STRING, 0);
}

scqParser::OrientedSetContext* scqParser::OperationOperandContext::orientedSet() {
  return getRuleContext<scqParser::OrientedSetContext>(0);
}

scqParser::TemplateCommandContext* scqParser::OperationOperandContext::templateCommand() {
  return getRuleContext<scqParser::TemplateCommandContext>(0);
}


size_t scqParser::OperationOperandContext::getRuleIndex() const {
  return scqParser::RuleOperationOperand;
}

void scqParser::OperationOperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperationOperand(this);
}

void scqParser::OperationOperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperationOperand(this);
}


antlrcpp::Any scqParser::OperationOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitOperationOperand(this);
  else
    return visitor->visitChildren(this);
}

scqParser::OperationOperandContext* scqParser::operationOperand(BlockContext::Objects * objects,size_t * paramNum,std::vector<std::vector<std::string>> * params) {
  OperationOperandContext *_localctx = _tracker.createInstance<OperationOperandContext>(_ctx, getState(), objects, paramNum, params);
  enterRule(_localctx, 18, scqParser::RuleOperationOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(222);
        dynamic_cast<OperationOperandContext *>(_localctx)->nameToken = match(scqParser::NAME);

            if (_localctx->objects->find((dynamic_cast<OperationOperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->nameToken->getText() : "")) == _localctx->objects->end()) {
              SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<OperationOperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->nameToken->getText() : "") + "\" isn't declared.");
            }

        	if (paramNum != nullptr && params != nullptr) {
         	  if (*paramNum < params->size()) {
        	    if (_localctx->objects->find((dynamic_cast<OperationOperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->nameToken->getText() : "")) == _localctx->objects->end()) {
        	      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<OperationOperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->nameToken->getText() : "") + "\" isn't declared.");
        	    }

        	    std::vector<std::string> & expectedTypes = _localctx->params->at(*_localctx->paramNum);
        	    std::string & type = (*_localctx->objects->find((dynamic_cast<OperationOperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->nameToken->getText() : ""))).second;
        	    if (std::find(expectedTypes.begin(), expectedTypes.end(), type) == expectedTypes.end()) {
        	      SC_THROW_EXCEPTION(
        	        utils::ExceptionInvalidParams,
        	        "Unexpected param \"" + (dynamic_cast<OperationOperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->nameToken->getText() : "") + "\" with type \"" + type + "\" in function call. Expected param with type \"" + expectedTypes.at(0) + "\".");
        	    }
              }
              ++(*_localctx->paramNum);
            }
            
        break;
      }

      case scqParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(224);
        dynamic_cast<OperationOperandContext *>(_localctx)->stringToken = match(scqParser::STRING);

        	if (paramNum != nullptr && params != nullptr) {
              if (*paramNum < params->size()) {
            	std::vector<std::string> & expectedTypes = _localctx->params->at(*_localctx->paramNum);
            	if (std::find(expectedTypes.begin(), expectedTypes.end(), "string") == expectedTypes.end()) {
            	  SC_THROW_EXCEPTION(
            	    utils::ExceptionInvalidParams,
            	    "Unexpected param \"" + (dynamic_cast<OperationOperandContext *>(_localctx)->stringToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->stringToken->getText() : "") + "\" with type \"string\" in function call. Expected param with type \"" + expectedTypes.at(0) + "\".");
            	}
              }
              ++(*_localctx->paramNum);
            }
            
        break;
      }

      case scqParser::LEFT_CURL_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(226);
        orientedSet(_localctx->objects, nullptr, nullptr);
        break;
      }

      case scqParser::LEFT_SQUARE_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(227);
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

scqParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState, BlockContext::Objects * objects, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->paramNum = paramNum;
  this->params = params;
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

void scqParser::OperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperand(this);
}

void scqParser::OperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperand(this);
}


antlrcpp::Any scqParser::OperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitOperand(this);
  else
    return visitor->visitChildren(this);
}

scqParser::OperandContext* scqParser::operand(BlockContext::Objects * objects,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params) {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState(), objects, paramNum, params);
  enterRule(_localctx, 20, scqParser::RuleOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(236);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(230);
        dynamic_cast<OperandContext *>(_localctx)->nameToken = match(scqParser::NAME);

         	if (paramNum != nullptr && params != nullptr) {
         	  if (*paramNum < params->size()) {
        	    if (_localctx->objects->find((dynamic_cast<OperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperandContext *>(_localctx)->nameToken->getText() : "")) == _localctx->objects->end()) {
        	      SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object " + (dynamic_cast<OperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperandContext *>(_localctx)->nameToken->getText() : "") + " isn't declared.");
        	    }

        	    std::string & expectedType = _localctx->params->at(*_localctx->paramNum).second;
        	    std::string & type = (*_localctx->objects->find((dynamic_cast<OperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperandContext *>(_localctx)->nameToken->getText() : ""))).second;
        	    if (expectedType != type) {
        	      SC_THROW_EXCEPTION(
        	        utils::ExceptionInvalidParams,
        	        "Unexpected param \"" + (dynamic_cast<OperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperandContext *>(_localctx)->nameToken->getText() : "") + "\" with type \"" + type + "\" in function call. Expected param with type \"" + expectedType + "\".");
        	    }
              }
              ++(*_localctx->paramNum);
            }
        	
        break;
      }

      case scqParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(232);
        match(scqParser::STRING);
        break;
      }

      case scqParser::LEFT_CURL_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(233);
        orientedSet(_localctx->objects, _localctx->paramNum, _localctx->params);
        break;
      }

      case scqParser::LEFT_FIGURE_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(234);
        nonOrientedSet(_localctx->objects, _localctx->paramNum, _localctx->params);
        break;
      }

      case scqParser::LEFT_SQUARE_BRACKET: {
        enterOuterAlt(_localctx, 5);
        setState(235);
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

scqParser::NonOrientedSetContext::NonOrientedSetContext(ParserRuleContext *parent, size_t invokingState, BlockContext::Objects * objects, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->paramNum = paramNum;
  this->params = params;
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

void scqParser::NonOrientedSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonOrientedSet(this);
}

void scqParser::NonOrientedSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonOrientedSet(this);
}


antlrcpp::Any scqParser::NonOrientedSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitNonOrientedSet(this);
  else
    return visitor->visitChildren(this);
}

scqParser::NonOrientedSetContext* scqParser::nonOrientedSet(BlockContext::Objects * objects,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params) {
  NonOrientedSetContext *_localctx = _tracker.createInstance<NonOrientedSetContext>(_ctx, getState(), objects, paramNum, params);
  enterRule(_localctx, 22, scqParser::RuleNonOrientedSet);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(scqParser::LEFT_FIGURE_BRACKET);

     	if (paramNum != nullptr && params != nullptr) {
     	  if (*paramNum < params->size()) {
     	    std::string & type = _localctx->params->at(*_localctx->paramNum).second;
     	    if (_localctx->params->at(*_localctx->paramNum).second != "set") {
     	      SC_THROW_EXCEPTION(
     	        utils::ExceptionInvalidParams,
     	        "Unexpected param with type \"set\" in function call. Expected param with type \"" + type + "\".");
     	    }
    	  }
     	  ++(*_localctx->paramNum);
     	}
     	
    setState(243);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::LEFT_SQUARE_BRACKET)
      | (1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::STRING)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(240);
      compositeOperand(_localctx->objects, nullptr, nullptr);
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(246);
      match(scqParser::COMMA);
      setState(247);
      compositeOperand(_localctx->objects, nullptr, nullptr);
      setState(252);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(253);
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

scqParser::OrientedSetContext::OrientedSetContext(ParserRuleContext *parent, size_t invokingState, BlockContext::Objects * objects, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->paramNum = paramNum;
  this->params = params;
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

void scqParser::OrientedSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrientedSet(this);
}

void scqParser::OrientedSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrientedSet(this);
}


antlrcpp::Any scqParser::OrientedSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitOrientedSet(this);
  else
    return visitor->visitChildren(this);
}

scqParser::OrientedSetContext* scqParser::orientedSet(BlockContext::Objects * objects,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params) {
  OrientedSetContext *_localctx = _tracker.createInstance<OrientedSetContext>(_ctx, getState(), objects, paramNum, params);
  enterRule(_localctx, 24, scqParser::RuleOrientedSet);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(scqParser::LEFT_CURL_BRACKET);

    	if (paramNum != nullptr && params != nullptr) {
    	  if (*paramNum < params->size()) {
            std::string & type = _localctx->params->at(*_localctx->paramNum).second;
            if (_localctx->params->at(*_localctx->paramNum).second != "tuple") {
              SC_THROW_EXCEPTION(
                utils::ExceptionInvalidParams,
                "Unexpected param with type \"tuple\" in function call. Expected param with type \"" + type + "\".");
            }
          }
    	  ++(*_localctx->paramNum);
    	}
        
    setState(260);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::LEFT_SQUARE_BRACKET)
      | (1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::STRING)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(257);
      compositeOperand(_localctx->objects, nullptr, nullptr);
      setState(262);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(263);
      match(scqParser::COMMA);
      setState(264);
      compositeOperand(_localctx->objects, nullptr, nullptr);
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(270);
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

void scqParser::TemplateCommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplateCommand(this);
}

void scqParser::TemplateCommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplateCommand(this);
}


antlrcpp::Any scqParser::TemplateCommandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitTemplateCommand(this);
  else
    return visitor->visitChildren(this);
}

scqParser::TemplateCommandContext* scqParser::templateCommand() {
  TemplateCommandContext *_localctx = _tracker.createInstance<TemplateCommandContext>(_ctx, getState());
  enterRule(_localctx, 26, scqParser::RuleTemplateCommand);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(272);
    templateExpression();
    setState(277);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(273);
        match(scqParser::COMMA);
        setState(274);
        templateExpression(); 
      }
      setState(279);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
    setState(281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scqParser::AS_OP) {
      setState(280);
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

void scqParser::TemplateExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplateExpression(this);
}

void scqParser::TemplateExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplateExpression(this);
}


antlrcpp::Any scqParser::TemplateExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitTemplateExpression(this);
  else
    return visitor->visitChildren(this);
}

scqParser::TemplateExpressionContext* scqParser::templateExpression() {
  TemplateExpressionContext *_localctx = _tracker.createInstance<TemplateExpressionContext>(_ctx, getState());
  enterRule(_localctx, 28, scqParser::RuleTemplateExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(scqParser::LEFT_SQUARE_BRACKET);
    setState(284);
    commandTemplate();
    setState(285);
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

void scqParser::CommandTemplateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommandTemplate(this);
}

void scqParser::CommandTemplateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommandTemplate(this);
}


antlrcpp::Any scqParser::CommandTemplateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitCommandTemplate(this);
  else
    return visitor->visitChildren(this);
}

scqParser::CommandTemplateContext* scqParser::commandTemplate() {
  CommandTemplateContext *_localctx = _tracker.createInstance<CommandTemplateContext>(_ctx, getState());
  enterRule(_localctx, 30, scqParser::RuleCommandTemplate);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    templateParam();
    setState(292);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(288);
      match(scqParser::COMMA);
      setState(289);
      templateParam();
      setState(294);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(295);
    match(scqParser::EDGE_OP);
    setState(296);
    templateParam();
    setState(301);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(297);
      match(scqParser::COMMA);
      setState(298);
      templateParam();
      setState(303);
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

void scqParser::CommandTemplateResultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommandTemplateResult(this);
}

void scqParser::CommandTemplateResultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommandTemplateResult(this);
}


antlrcpp::Any scqParser::CommandTemplateResultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitCommandTemplateResult(this);
  else
    return visitor->visitChildren(this);
}

scqParser::CommandTemplateResultContext* scqParser::commandTemplateResult() {
  CommandTemplateResultContext *_localctx = _tracker.createInstance<CommandTemplateResultContext>(_ctx, getState());
  enterRule(_localctx, 32, scqParser::RuleCommandTemplateResult);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    match(scqParser::AS_OP);
    setState(305);
    match(scqParser::LEFT_SQUARE_BRACKET);
    setState(306);
    templateParam();
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(307);
      match(scqParser::COMMA);
      setState(308);
      templateParam();
      setState(313);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(314);
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

scqParser::SetOperationContext* scqParser::TemplateParamContext::setOperation() {
  return getRuleContext<scqParser::SetOperationContext>(0);
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

void scqParser::TemplateParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplateParam(this);
}

void scqParser::TemplateParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplateParam(this);
}


antlrcpp::Any scqParser::TemplateParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitTemplateParam(this);
  else
    return visitor->visitChildren(this);
}

scqParser::TemplateParamContext* scqParser::templateParam() {
  TemplateParamContext *_localctx = _tracker.createInstance<TemplateParamContext>(_ctx, getState());
  enterRule(_localctx, 34, scqParser::RuleTemplateParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::T__0:
      case scqParser::T__1:
      case scqParser::T__2:
      case scqParser::T__3:
      case scqParser::T__4:
      case scqParser::T__5:
      case scqParser::T__6:
      case scqParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(316);
        setOperation(&_localctx->paramTypes);
        break;
      }

      case scqParser::OBJECT_TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(317);
        match(scqParser::OBJECT_TYPE);
        break;
      }

      case scqParser::NAME: {
        enterOuterAlt(_localctx, 3);
        setState(318);
        match(scqParser::NAME);
        break;
      }

      case scqParser::LEFT_TRIANGLE_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(319);
        match(scqParser::LEFT_TRIANGLE_BRACKET);
        setState(320);
        match(scqParser::NAME);
        setState(321);
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

//----------------- SetOperationContext ------------------------------------------------------------------

scqParser::SetOperationContext::SetOperationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::SetOperationContext::SetOperationContext(ParserRuleContext *parent, size_t invokingState, std::vector<std::vector<std::string>> * paramTypes)
  : ParserRuleContext(parent, invokingState) {
  this->paramTypes = paramTypes;
}


size_t scqParser::SetOperationContext::getRuleIndex() const {
  return scqParser::RuleSetOperation;
}

void scqParser::SetOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetOperation(this);
}

void scqParser::SetOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scqListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetOperation(this);
}


antlrcpp::Any scqParser::SetOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scqVisitor*>(visitor))
    return parserVisitor->visitSetOperation(this);
  else
    return visitor->visitChildren(this);
}

scqParser::SetOperationContext* scqParser::setOperation(std::vector<std::vector<std::string>> * paramTypes) {
  SetOperationContext *_localctx = _tracker.createInstance<SetOperationContext>(_ctx, getState(), paramTypes);
  enterRule(_localctx, 36, scqParser::RuleSetOperation);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(340);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(324);
        match(scqParser::T__0);

        	paramTypes->push_back({ "set" });
        	paramTypes->push_back({ "set" });
        	
        break;
      }

      case scqParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(326);
        match(scqParser::T__1);

            paramTypes->push_back({ "set" });
            paramTypes->push_back({ "set" });
            
        break;
      }

      case scqParser::T__2: {
        enterOuterAlt(_localctx, 3);
        setState(328);
        match(scqParser::T__2);

        	paramTypes->push_back({ "set" });
        	paramTypes->push_back({ "set" });
            
        break;
      }

      case scqParser::T__3: {
        enterOuterAlt(_localctx, 4);
        setState(330);
        match(scqParser::T__3);

            paramTypes->push_back({ "set", "tuple", "terminal" });
            
        break;
      }

      case scqParser::T__4: {
        enterOuterAlt(_localctx, 5);
        setState(332);
        match(scqParser::T__4);

        	paramTypes->push_back({ "set", "tuple", "terminal" });
            paramTypes->push_back({ "string" });
            
        break;
      }

      case scqParser::T__5: {
        enterOuterAlt(_localctx, 6);
        setState(334);
        match(scqParser::T__5);

        	paramTypes->push_back({ "set", "tuple", "terminal" });
            paramTypes->push_back({ "set", "tuple", "terminal" });
        	
        break;
      }

      case scqParser::T__6: {
        enterOuterAlt(_localctx, 7);
        setState(336);
        match(scqParser::T__6);

            paramTypes->push_back({ "set", "tuple", "terminal" });
            
        break;
      }

      case scqParser::T__7: {
        enterOuterAlt(_localctx, 8);
        setState(338);
        match(scqParser::T__7);

           	paramTypes->push_back({ "set", "tuple", "terminal" });
           	paramTypes->push_back({ "set", "tuple", "terminal" });
           	paramTypes->push_back({ "set", "tuple", "terminal" });
            paramTypes->push_back({ "set", "tuple", "terminal" });
            paramTypes->push_back({ "set", "tuple", "terminal" });
            paramTypes->push_back({ "set", "tuple", "terminal" });
            
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
  "program", "procDeclaration", "procDefinition", "procParams", "block", 
  "objectDeclaration", "objectDefinition", "operation", "compositeOperand", 
  "operationOperand", "operand", "nonOrientedSet", "orientedSet", "templateCommand", 
  "templateExpression", "commandTemplate", "commandTemplateResult", "templateParam", 
  "setOperation"
};

std::vector<std::string> scqParser::_literalNames = {
  "", "'intersect'", "'complement'", "'unite'", "'remove'", "'set_idtf'", 
  "'equal'", "'dump'", "'return'", "'->'", "':='", "'as'", "'if'", "'elif'", 
  "'<'", "'>'", "'['", "']'", "'{'", "'}'", "'('", "')'", "','", "';'", 
  "'procedure'"
};

std::vector<std::string> scqParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "EDGE_OP", "ASSIGN_OP", "AS_OP", "IF_OP", 
  "ELSE_OP", "LEFT_TRIANGLE_BRACKET", "RIGHT_TRIANGLE_BRACKET", "LEFT_SQUARE_BRACKET", 
  "RIGHT_SQUARE_BRACKET", "LEFT_FIGURE_BRACKET", "RIGHT_FIGURE_BRACKET", 
  "LEFT_CURL_BRACKET", "RIGHT_CURL_BRACKET", "COMMA", "SEMICOLON", "PROCEDURE_TYPE", 
  "OBJECT_TYPE", "STRING", "NAME", "LETTER", "DIGIT", "WS", "SL_COMMENT"
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x21, 0x159, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x3, 0x2, 0x7, 0x2, 0x2a, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
       0x2d, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x30, 0xa, 0x2, 0xc, 0x2, 0xe, 
       0x2, 0x33, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x3e, 0xa, 
       0x3, 0xc, 0x3, 0xe, 0x3, 0x41, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x4, 0x3, 0x4, 0x5, 0x4, 0x47, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
       0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x57, 
       0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5a, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x7, 0x5, 0x5f, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x62, 0xb, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x66, 0xa, 0x5, 0xc, 0x5, 0xe, 
       0x5, 0x69, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x7, 0x6, 0x70, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x73, 0xb, 0x6, 
       0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7a, 
       0xa, 0x7, 0x7, 0x7, 0x7c, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x7f, 0xb, 
       0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x7, 0x7, 0x87, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x8a, 0xb, 0x7, 0x3, 
       0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x91, 0xa, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x97, 0xa, 
       0x8, 0x7, 0x8, 0x99, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x9c, 0xb, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x5, 0x8, 0xa6, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
       0x8, 0xaa, 0xa, 0x8, 0x5, 0x8, 0xac, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xb3, 0xa, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xb9, 0xa, 0x9, 0xc, 0x9, 
       0xe, 0x9, 0xbc, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
       0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
       0x9, 0xc8, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xcd, 
       0xa, 0x9, 0x7, 0x9, 0xcf, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xd2, 0xb, 
       0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xd7, 0xa, 0x9, 0x3, 
       0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xdc, 0xa, 0xa, 0xc, 0xa, 0xe, 
       0xa, 0xdf, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
       0xb, 0x3, 0xb, 0x5, 0xb, 0xe7, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xef, 0xa, 0xc, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xf4, 0xa, 0xd, 0xc, 0xd, 0xe, 
       0xd, 0xf7, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xfb, 0xa, 0xd, 
       0xc, 0xd, 0xe, 0xd, 0xfe, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
       0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x105, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 
       0x108, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x10c, 0xa, 0xe, 0xc, 
       0xe, 0xe, 0xe, 0x10f, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x7, 0xf, 0x116, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x119, 
       0xb, 0xf, 0x3, 0xf, 0x5, 0xf, 0x11c, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 
       0x125, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x128, 0xb, 0x11, 0x3, 0x11, 
       0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x12e, 0xa, 0x11, 0xc, 
       0x11, 0xe, 0x11, 0x131, 0xb, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x138, 0xa, 0x12, 0xc, 0x12, 0xe, 
       0x12, 0x13b, 0xb, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x145, 0xa, 
       0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x157, 
       0xa, 0x14, 0x3, 0x14, 0x2, 0x2, 0x15, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x2, 0x2, 0x2, 0x179, 0x2, 0x2b, 0x3, 0x2, 0x2, 0x2, 
       0x4, 0x36, 0x3, 0x2, 0x2, 0x2, 0x6, 0x46, 0x3, 0x2, 0x2, 0x2, 0x8, 
       0x51, 0x3, 0x2, 0x2, 0x2, 0xa, 0x71, 0x3, 0x2, 0x2, 0x2, 0xc, 0x74, 
       0x3, 0x2, 0x2, 0x2, 0xe, 0xab, 0x3, 0x2, 0x2, 0x2, 0x10, 0xd6, 0x3, 
       0x2, 0x2, 0x2, 0x12, 0xd8, 0x3, 0x2, 0x2, 0x2, 0x14, 0xe6, 0x3, 0x2, 
       0x2, 0x2, 0x16, 0xee, 0x3, 0x2, 0x2, 0x2, 0x18, 0xf0, 0x3, 0x2, 0x2, 
       0x2, 0x1a, 0x101, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x112, 0x3, 0x2, 0x2, 
       0x2, 0x1e, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x20, 0x121, 0x3, 0x2, 0x2, 
       0x2, 0x22, 0x132, 0x3, 0x2, 0x2, 0x2, 0x24, 0x144, 0x3, 0x2, 0x2, 
       0x2, 0x26, 0x156, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2a, 0x5, 0x4, 0x3, 
       0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2d, 0x3, 0x2, 0x2, 0x2, 
       0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 
       0x5, 0x6, 0x4, 0x2, 0x2f, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 
       0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 
       0x2, 0x2, 0x32, 0x34, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 
       0x2, 0x34, 0x35, 0x5, 0xa, 0x6, 0x2, 0x35, 0x3, 0x3, 0x2, 0x2, 0x2, 
       0x36, 0x37, 0x7, 0x1a, 0x2, 0x2, 0x37, 0x38, 0x7, 0xb, 0x2, 0x2, 
       0x38, 0x39, 0x7, 0x1d, 0x2, 0x2, 0x39, 0x3f, 0x8, 0x3, 0x1, 0x2, 
       0x3a, 0x3b, 0x7, 0x18, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x1d, 0x2, 0x2, 
       0x3c, 0x3e, 0x8, 0x3, 0x1, 0x2, 0x3d, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3e, 
       0x41, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 
       0x3, 0x2, 0x2, 0x2, 0x40, 0x42, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 
       0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 0x19, 0x2, 0x2, 0x43, 0x5, 0x3, 0x2, 
       0x2, 0x2, 0x44, 0x45, 0x7, 0x1a, 0x2, 0x2, 0x45, 0x47, 0x7, 0xb, 
       0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x3, 0x2, 0x2, 
       0x2, 0x47, 0x48, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x1d, 0x2, 
       0x2, 0x49, 0x4a, 0x8, 0x4, 0x1, 0x2, 0x4a, 0x4b, 0x7, 0xc, 0x2, 0x2, 
       0x4b, 0x4c, 0x5, 0x8, 0x5, 0x2, 0x4c, 0x4d, 0x7, 0x18, 0x2, 0x2, 
       0x4d, 0x4e, 0x5, 0xa, 0x6, 0x2, 0x4e, 0x4f, 0x8, 0x4, 0x1, 0x2, 0x4f, 
       0x50, 0x7, 0x19, 0x2, 0x2, 0x50, 0x7, 0x3, 0x2, 0x2, 0x2, 0x51, 0x58, 
       0x7, 0x16, 0x2, 0x2, 0x52, 0x53, 0x7, 0x1b, 0x2, 0x2, 0x53, 0x54, 
       0x7, 0xb, 0x2, 0x2, 0x54, 0x55, 0x7, 0x1d, 0x2, 0x2, 0x55, 0x57, 
       0x8, 0x5, 0x1, 0x2, 0x56, 0x52, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 
       0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 
       0x2, 0x2, 0x59, 0x67, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 
       0x2, 0x5b, 0x60, 0x7, 0x18, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x1b, 0x2, 
       0x2, 0x5d, 0x5f, 0x7, 0xb, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 
       0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x63, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 
       0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x1d, 0x2, 0x2, 0x64, 0x66, 
       0x8, 0x5, 0x1, 0x2, 0x65, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x3, 
       0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 
       0x2, 0x2, 0x68, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 
       0x2, 0x6a, 0x6b, 0x7, 0x17, 0x2, 0x2, 0x6b, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0x6c, 0x70, 0x5, 0xc, 0x7, 0x2, 0x6d, 0x70, 0x5, 0xe, 0x8, 0x2, 0x6e, 
       0x70, 0x5, 0x10, 0x9, 0x2, 0x6f, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 
       0x2, 0x2, 0x2, 0x72, 0xb, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 
       0x2, 0x2, 0x74, 0x7d, 0x7, 0x1b, 0x2, 0x2, 0x75, 0x79, 0x7, 0x18, 
       0x2, 0x2, 0x76, 0x7a, 0x7, 0x1b, 0x2, 0x2, 0x77, 0x78, 0x7, 0x1d, 
       0x2, 0x2, 0x78, 0x7a, 0x8, 0x7, 0x1, 0x2, 0x79, 0x76, 0x3, 0x2, 0x2, 
       0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7c, 0x3, 0x2, 0x2, 0x2, 
       0x7b, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7d, 
       0x7b, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 
       0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 
       0xb, 0x2, 0x2, 0x81, 0x82, 0x7, 0x1d, 0x2, 0x2, 0x82, 0x88, 0x8, 
       0x7, 0x1, 0x2, 0x83, 0x84, 0x7, 0x18, 0x2, 0x2, 0x84, 0x85, 0x7, 
       0x1d, 0x2, 0x2, 0x85, 0x87, 0x8, 0x7, 0x1, 0x2, 0x86, 0x83, 0x3, 
       0x2, 0x2, 0x2, 0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 
       0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 
       0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x7, 0x19, 0x2, 
       0x2, 0x8c, 0xd, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x91, 0x7, 0x1b, 0x2, 0x2, 
       0x8e, 0x8f, 0x7, 0x1d, 0x2, 0x2, 0x8f, 0x91, 0x8, 0x8, 0x1, 0x2, 
       0x90, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 
       0x9a, 0x3, 0x2, 0x2, 0x2, 0x92, 0x96, 0x7, 0x18, 0x2, 0x2, 0x93, 
       0x97, 0x7, 0x1b, 0x2, 0x2, 0x94, 0x95, 0x7, 0x1d, 0x2, 0x2, 0x95, 
       0x97, 0x8, 0x8, 0x1, 0x2, 0x96, 0x93, 0x3, 0x2, 0x2, 0x2, 0x96, 0x94, 
       0x3, 0x2, 0x2, 0x2, 0x97, 0x99, 0x3, 0x2, 0x2, 0x2, 0x98, 0x92, 0x3, 
       0x2, 0x2, 0x2, 0x99, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 
       0x2, 0x2, 0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 
       0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0xb, 0x2, 0x2, 
       0x9e, 0x9f, 0x5, 0x12, 0xa, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 
       0xa0, 0xa1, 0x8, 0x8, 0x1, 0x2, 0xa1, 0xac, 0x3, 0x2, 0x2, 0x2, 0xa2, 
       0xa3, 0x7, 0x1d, 0x2, 0x2, 0xa3, 0xa4, 0x8, 0x8, 0x1, 0x2, 0xa4, 
       0xa6, 0x7, 0xc, 0x2, 0x2, 0xa5, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 
       0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 0x5, 
       0x12, 0xa, 0x2, 0xa8, 0xaa, 0x5, 0x10, 0x9, 0x2, 0xa9, 0xa5, 0x3, 
       0x2, 0x2, 0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xac, 0x3, 0x2, 
       0x2, 0x2, 0xab, 0x90, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 
       0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x7, 0x19, 0x2, 
       0x2, 0xae, 0xf, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb3, 0x5, 0x26, 0x14, 
       0x2, 0xb0, 0xb1, 0x7, 0x1d, 0x2, 0x2, 0xb1, 0xb3, 0x8, 0x9, 0x1, 
       0x2, 0xb2, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 
       0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0xb, 0x2, 0x2, 0xb5, 
       0xba, 0x5, 0x14, 0xb, 0x2, 0xb6, 0xb7, 0x7, 0x18, 0x2, 0x2, 0xb7, 
       0xb9, 0x5, 0x14, 0xb, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 
       0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 
       0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xba, 0x3, 
       0x2, 0x2, 0x2, 0xbd, 0xbe, 0x8, 0x9, 0x1, 0x2, 0xbe, 0xbf, 0x7, 0x19, 
       0x2, 0x2, 0xbf, 0xc0, 0x8, 0x9, 0x1, 0x2, 0xc0, 0xd7, 0x3, 0x2, 0x2, 
       0x2, 0xc1, 0xc2, 0x7, 0xe, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0xb, 0x2, 0x2, 
       0xc3, 0xc4, 0x5, 0x10, 0x9, 0x2, 0xc4, 0xc7, 0x7, 0x18, 0x2, 0x2, 
       0xc5, 0xc8, 0x5, 0x10, 0x9, 0x2, 0xc6, 0xc8, 0x5, 0xe, 0x8, 0x2, 
       0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 
       0xd0, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcc, 0x7, 0x18, 0x2, 0x2, 0xca, 
       0xcd, 0x5, 0x10, 0x9, 0x2, 0xcb, 0xcd, 0x5, 0xe, 0x8, 0x2, 0xcc, 
       0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcf, 
       0x3, 0x2, 0x2, 0x2, 0xce, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd2, 0x3, 
       0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 0x2, 
       0x2, 0x2, 0xd1, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 
       0x2, 0xd3, 0xd4, 0x8, 0x9, 0x1, 0x2, 0xd4, 0xd5, 0x7, 0x19, 0x2, 
       0x2, 0xd5, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xb2, 0x3, 0x2, 0x2, 0x2, 
       0xd6, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xd7, 0x11, 0x3, 0x2, 0x2, 0x2, 0xd8, 
       0xdd, 0x5, 0x16, 0xc, 0x2, 0xd9, 0xda, 0x7, 0x18, 0x2, 0x2, 0xda, 
       0xdc, 0x5, 0x16, 0xc, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdc, 
       0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 
       0x3, 0x2, 0x2, 0x2, 0xde, 0x13, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 
       0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x1d, 0x2, 0x2, 0xe1, 0xe7, 0x8, 
       0xb, 0x1, 0x2, 0xe2, 0xe3, 0x7, 0x1c, 0x2, 0x2, 0xe3, 0xe7, 0x8, 
       0xb, 0x1, 0x2, 0xe4, 0xe7, 0x5, 0x1a, 0xe, 0x2, 0xe5, 0xe7, 0x5, 
       0x1c, 0xf, 0x2, 0xe6, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe2, 0x3, 
       0x2, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe5, 0x3, 0x2, 
       0x2, 0x2, 0xe7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x7, 0x1d, 
       0x2, 0x2, 0xe9, 0xef, 0x8, 0xc, 0x1, 0x2, 0xea, 0xef, 0x7, 0x1c, 
       0x2, 0x2, 0xeb, 0xef, 0x5, 0x1a, 0xe, 0x2, 0xec, 0xef, 0x5, 0x18, 
       0xd, 0x2, 0xed, 0xef, 0x5, 0x1c, 0xf, 0x2, 0xee, 0xe8, 0x3, 0x2, 
       0x2, 0x2, 0xee, 0xea, 0x3, 0x2, 0x2, 0x2, 0xee, 0xeb, 0x3, 0x2, 0x2, 
       0x2, 0xee, 0xec, 0x3, 0x2, 0x2, 0x2, 0xee, 0xed, 0x3, 0x2, 0x2, 0x2, 
       0xef, 0x17, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x14, 0x2, 0x2, 
       0xf1, 0xf5, 0x8, 0xd, 0x1, 0x2, 0xf2, 0xf4, 0x5, 0x12, 0xa, 0x2, 
       0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 
       0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xfc, 
       0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 
       0x18, 0x2, 0x2, 0xf9, 0xfb, 0x5, 0x12, 0xa, 0x2, 0xfa, 0xf8, 0x3, 
       0x2, 0x2, 0x2, 0xfb, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 
       0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xff, 0x3, 0x2, 0x2, 
       0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x15, 0x2, 
       0x2, 0x100, 0x19, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 0x16, 0x2, 
       0x2, 0x102, 0x106, 0x8, 0xe, 0x1, 0x2, 0x103, 0x105, 0x5, 0x12, 0xa, 
       0x2, 0x104, 0x103, 0x3, 0x2, 0x2, 0x2, 0x105, 0x108, 0x3, 0x2, 0x2, 
       0x2, 0x106, 0x104, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 
       0x2, 0x107, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x108, 0x106, 0x3, 0x2, 0x2, 
       0x2, 0x109, 0x10a, 0x7, 0x18, 0x2, 0x2, 0x10a, 0x10c, 0x5, 0x12, 
       0xa, 0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 0x3, 0x2, 
       0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 
       0x2, 0x2, 0x10e, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 
       0x2, 0x2, 0x110, 0x111, 0x7, 0x17, 0x2, 0x2, 0x111, 0x1b, 0x3, 0x2, 
       0x2, 0x2, 0x112, 0x117, 0x5, 0x1e, 0x10, 0x2, 0x113, 0x114, 0x7, 
       0x18, 0x2, 0x2, 0x114, 0x116, 0x5, 0x1e, 0x10, 0x2, 0x115, 0x113, 
       0x3, 0x2, 0x2, 0x2, 0x116, 0x119, 0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11c, 
       0x5, 0x22, 0x12, 0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 
       0x3, 0x2, 0x2, 0x2, 0x11c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 
       0x7, 0x12, 0x2, 0x2, 0x11e, 0x11f, 0x5, 0x20, 0x11, 0x2, 0x11f, 0x120, 
       0x7, 0x13, 0x2, 0x2, 0x120, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x126, 
       0x5, 0x24, 0x13, 0x2, 0x122, 0x123, 0x7, 0x18, 0x2, 0x2, 0x123, 0x125, 
       0x5, 0x24, 0x13, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x125, 0x128, 
       0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x129, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 
       0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x7, 0xb, 0x2, 0x2, 0x12a, 0x12f, 
       0x5, 0x24, 0x13, 0x2, 0x12b, 0x12c, 0x7, 0x18, 0x2, 0x2, 0x12c, 0x12e, 
       0x5, 0x24, 0x13, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x131, 
       0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x130, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x21, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 
       0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x7, 0xd, 0x2, 0x2, 0x133, 0x134, 
       0x7, 0x12, 0x2, 0x2, 0x134, 0x139, 0x5, 0x24, 0x13, 0x2, 0x135, 0x136, 
       0x7, 0x18, 0x2, 0x2, 0x136, 0x138, 0x5, 0x24, 0x13, 0x2, 0x137, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13c, 
       0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 
       0x7, 0x13, 0x2, 0x2, 0x13d, 0x23, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x145, 
       0x5, 0x26, 0x14, 0x2, 0x13f, 0x145, 0x7, 0x1b, 0x2, 0x2, 0x140, 0x145, 
       0x7, 0x1d, 0x2, 0x2, 0x141, 0x142, 0x7, 0x10, 0x2, 0x2, 0x142, 0x143, 
       0x7, 0x1d, 0x2, 0x2, 0x143, 0x145, 0x7, 0x11, 0x2, 0x2, 0x144, 0x13e, 
       0x3, 0x2, 0x2, 0x2, 0x144, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x144, 0x140, 
       0x3, 0x2, 0x2, 0x2, 0x144, 0x141, 0x3, 0x2, 0x2, 0x2, 0x145, 0x25, 
       0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x7, 0x3, 0x2, 0x2, 0x147, 0x157, 
       0x8, 0x14, 0x1, 0x2, 0x148, 0x149, 0x7, 0x4, 0x2, 0x2, 0x149, 0x157, 
       0x8, 0x14, 0x1, 0x2, 0x14a, 0x14b, 0x7, 0x5, 0x2, 0x2, 0x14b, 0x157, 
       0x8, 0x14, 0x1, 0x2, 0x14c, 0x14d, 0x7, 0x6, 0x2, 0x2, 0x14d, 0x157, 
       0x8, 0x14, 0x1, 0x2, 0x14e, 0x14f, 0x7, 0x7, 0x2, 0x2, 0x14f, 0x157, 
       0x8, 0x14, 0x1, 0x2, 0x150, 0x151, 0x7, 0x8, 0x2, 0x2, 0x151, 0x157, 
       0x8, 0x14, 0x1, 0x2, 0x152, 0x153, 0x7, 0x9, 0x2, 0x2, 0x153, 0x157, 
       0x8, 0x14, 0x1, 0x2, 0x154, 0x155, 0x7, 0xa, 0x2, 0x2, 0x155, 0x157, 
       0x8, 0x14, 0x1, 0x2, 0x156, 0x146, 0x3, 0x2, 0x2, 0x2, 0x156, 0x148, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x156, 0x14c, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x156, 0x150, 
       0x3, 0x2, 0x2, 0x2, 0x156, 0x152, 0x3, 0x2, 0x2, 0x2, 0x156, 0x154, 
       0x3, 0x2, 0x2, 0x2, 0x157, 0x27, 0x3, 0x2, 0x2, 0x2, 0x28, 0x2b, 
       0x31, 0x3f, 0x46, 0x58, 0x60, 0x67, 0x6f, 0x71, 0x79, 0x7d, 0x88, 
       0x90, 0x96, 0x9a, 0xa5, 0xa9, 0xab, 0xb2, 0xba, 0xc7, 0xcc, 0xd0, 
       0xd6, 0xdd, 0xe6, 0xee, 0xf5, 0xfc, 0x106, 0x10d, 0x117, 0x11b, 0x126, 
       0x12f, 0x139, 0x144, 0x156, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

scqParser::Initializer scqParser::_init;
