
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


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


scqParser::ProgramContext* scqParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, scqParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(40);
        procDeclaration(_localctx->procs); 
      }
      setState(45);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(49);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(46);
        procDefinition(_localctx->procs, _localctx->procDefs); 
      }
      setState(51);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(52);
    block(_localctx->procDefs, nullptr, _localctx->objDefs, _localctx->objects);
   
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


scqParser::ProcDeclarationContext* scqParser::procDeclaration(ProgramContext::Procedures * procs) {
  ProcDeclarationContext *_localctx = _tracker.createInstance<ProcDeclarationContext>(_ctx, getState(), procs);
  enterRule(_localctx, 2, scqParser::RuleProcDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(scqParser::PROCEDURE_TYPE);
    setState(55);
    match(scqParser::EDGE_OP);
    setState(56);
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
    while (_la == scqParser::COMMA) {
      setState(58);
      match(scqParser::COMMA);
      setState(59);
      dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken = match(scqParser::NAME);

          if (_localctx->procs->find((dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "")) != _localctx->procs->end()) {
            SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + (dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" is declared.");
          }
          else {
            _localctx->procs->insert((dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : ""));
            SC_LOG_DEBUG("Declare \"" + (dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" procedure");
          }
          
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
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


scqParser::ProcDefinitionContext* scqParser::procDefinition(ProgramContext::Procedures * procs,ProgramContext::ProcedureDefinitions * procDefs) {
  ProcDefinitionContext *_localctx = _tracker.createInstance<ProcDefinitionContext>(_ctx, getState(), procs, procDefs);
  enterRule(_localctx, 4, scqParser::RuleProcDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scqParser::PROCEDURE_TYPE) {
      setState(68);
      match(scqParser::PROCEDURE_TYPE);
      setState(69);
      match(scqParser::EDGE_OP);
    }
    setState(72);
    dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken = match(scqParser::NAME);

        if (_localctx->procs->find((dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken->getText() : "")) == _localctx->procs->end()) {
          SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The procedure \"" + (dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken->getText() : "") + "\" isn't declared.");
        }
        
    setState(74);
    match(scqParser::ASSIGN_OP);
    setState(75);
    procParams(_localctx->params);
    setState(76);
    match(scqParser::COMMA);
    setState(77);
    block(_localctx->procDefs, _localctx->params, _localctx->objDefs, _localctx->objects);

     	_localctx->procDefs->insert({ (dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken->getText() : ""), { _localctx->params, { _localctx->objDefs, _localctx->objects } } });
        SC_LOG_DEBUG("Define \"" + (dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcDefinitionContext *>(_localctx)->nameToken->getText() : "") + "\" procedure");
     	
    setState(79);
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


scqParser::ProcParamsContext* scqParser::procParams(ProcDefinitionContext::ProcedureParams * params) {
  ProcParamsContext *_localctx = _tracker.createInstance<ProcParamsContext>(_ctx, getState(), params);
  enterRule(_localctx, 6, scqParser::RuleProcParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(scqParser::LEFT_CURL_BRACKET);
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::OBJECT_TYPE) {
      setState(82);
      dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken = match(scqParser::OBJECT_TYPE);
      setState(83);
      match(scqParser::EDGE_OP);
      setState(84);
      dynamic_cast<ProcParamsContext *>(_localctx)->nameToken = match(scqParser::NAME);

      	if (std::find_if(_localctx->params->begin(), _localctx->params->end(), [&](auto & item) -> bool { item.first == (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : ""); })
      	  != _localctx->params->end()) {
            SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param \"" + (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : "") + "\" is repeated.");
          }
          else {
            _localctx->params->push_back({ (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : ""), (dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken->getText() : "") });
            SC_LOG_DEBUG("Define \"" + (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : "") + "\" param");
          }
      	
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(91);
      match(scqParser::COMMA);
      setState(96);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == scqParser::OBJECT_TYPE) {
        setState(92);
        dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken = match(scqParser::OBJECT_TYPE);
        setState(93);
        match(scqParser::EDGE_OP);
        setState(98);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(99);
      dynamic_cast<ProcParamsContext *>(_localctx)->nameToken = match(scqParser::NAME);

          if (std::find_if(_localctx->params->begin(), _localctx->params->end(), [&](auto & item) -> bool { item.first == (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : ""); })
            != _localctx->params->end()) {
            SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The param \"" + (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : "") + "\" is repeated.");
          }
          else {
            _localctx->params->push_back({ (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : ""), (dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->object_typeToken->getText() : "") });
            SC_LOG_DEBUG("Define \"" + (dynamic_cast<ProcParamsContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ProcParamsContext *>(_localctx)->nameToken->getText() : "") + "\" param");
          }
          
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(106);
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

scqParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::ProcedureDefinitions * procDefs, ProcDefinitionContext::ProcedureParams * params, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::Objects * objects)
  : ParserRuleContext(parent, invokingState) {
  this->procDefs = procDefs;
  this->params = params;
  this->objDefs = objDefs;
  this->objects = objects;
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


scqParser::BlockContext* scqParser::block(ProgramContext::ProcedureDefinitions * procDefs,ProcDefinitionContext::ProcedureParams * params,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::Objects * objects) {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState(), procDefs, params, objDefs, objects);
  enterRule(_localctx, 8, scqParser::RuleBlock);

      if (params != nullptr) {
        std::for_each(params->begin(), params->end(), [&](const auto & item) {
          _localctx->objects->insert(item);
        });
      }
      
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::T__1)
      | (1ULL << scqParser::T__2)
      | (1ULL << scqParser::T__3)
      | (1ULL << scqParser::T__4)
      | (1ULL << scqParser::T__5)
      | (1ULL << scqParser::T__6)
      | (1ULL << scqParser::T__7)
      | (1ULL << scqParser::T__8)
      | (1ULL << scqParser::IF_OP)
      | (1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::OBJECT_TYPE)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(111);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(108);
        objectDeclaration(_localctx->objects, _localctx->procDefs);
        break;
      }

      case 2: {
        setState(109);
        objectDefinition(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
        break;
      }

      case 3: {
        setState(110);
        operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
        break;
      }

      }
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   _ctx->stop = _input->LT(-1);

    //    for (auto const & item : *_localctx->objDefs) {
    //      std::cout << "<" << item.at(0)
    //      		<< ">  <" << item.at(1)
    //      		<< ">  <" << item.at(2)
    //      		<< ">  <" << item.at(3)
    //      		<< ">" << std::endl;
    //	}
        
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

scqParser::ObjectDeclarationContext::ObjectDeclarationContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ProcedureDefinitions * procDefs)
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


scqParser::ObjectDeclarationContext* scqParser::objectDeclaration(ProgramContext::Objects * objects,ProgramContext::ProcedureDefinitions * procDefs) {
  ObjectDeclarationContext *_localctx = _tracker.createInstance<ObjectDeclarationContext>(_ctx, getState(), objects, procDefs);
  enterRule(_localctx, 10, scqParser::RuleObjectDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken = match(scqParser::OBJECT_TYPE);
    setState(125);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(117);
      match(scqParser::COMMA);
      setState(121);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case scqParser::OBJECT_TYPE: {
          setState(118);
          dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken = match(scqParser::OBJECT_TYPE);
          break;
        }

        case scqParser::NAME: {
          setState(119);
          dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken = match(scqParser::NAME);

              if (_localctx->objects->find((dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "")) == _localctx->objects->end()) {
                SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" isn't declared.");
              }
              
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(127);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(128);
    match(scqParser::EDGE_OP);
    setState(129);
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
    while (_la == scqParser::COMMA) {
      setState(131);
      match(scqParser::COMMA);
      setState(132);
      dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken = match(scqParser::NAME);

          if (_localctx->objects->find((dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "")) != _localctx->objects->end()) {
            SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" is declared.");
          }
          else {
            _localctx->objects->insert({ (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : ""), (dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->object_typeToken->getText() : "") });
            SC_LOG_DEBUG("Declare \"" + (dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<ObjectDeclarationContext *>(_localctx)->nameToken->getText() : "") + "\" object");
          }
          
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(139);
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

scqParser::ObjectDefinitionContext::ObjectDefinitionContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
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

tree::TerminalNode* scqParser::ObjectDefinitionContext::OBJECT_TYPE() {
  return getToken(scqParser::OBJECT_TYPE, 0);
}

scqParser::AssignableContext* scqParser::ObjectDefinitionContext::assignable() {
  return getRuleContext<scqParser::AssignableContext>(0);
}

scqParser::OperationContext* scqParser::ObjectDefinitionContext::operation() {
  return getRuleContext<scqParser::OperationContext>(0);
}

std::vector<tree::TerminalNode *> scqParser::ObjectDefinitionContext::NAME() {
  return getTokens(scqParser::NAME);
}

tree::TerminalNode* scqParser::ObjectDefinitionContext::NAME(size_t i) {
  return getToken(scqParser::NAME, i);
}

tree::TerminalNode* scqParser::ObjectDefinitionContext::ASSIGN_OP() {
  return getToken(scqParser::ASSIGN_OP, 0);
}


size_t scqParser::ObjectDefinitionContext::getRuleIndex() const {
  return scqParser::RuleObjectDefinition;
}


scqParser::ObjectDefinitionContext* scqParser::objectDefinition(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  ObjectDefinitionContext *_localctx = _tracker.createInstance<ObjectDefinitionContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 12, scqParser::RuleObjectDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(150);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(141);
        match(scqParser::OBJECT_TYPE);
        break;
      }

      case 2: {
        setState(144);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          setState(142);
          dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0 = match(scqParser::NAME);
          setState(143);
          match(scqParser::ASSIGN_OP);
          break;
        }

        }
        setState(146);
        dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 = match(scqParser::NAME);

        	auto const & it = _localctx->procDefs->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""));
        	if (it != _localctx->procDefs->end()) {
        	  dynamic_cast<ObjectDefinitionContext *>(_localctx)->funcParams =  (*procDefs->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""))).second.first;
        	  SC_LOG_DEBUG("Define \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : "") + "\" function call");
        	  _localctx->objDefs->push_back({ "call", (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""), std::to_string(_localctx->funcParams->size()), "" });
        	}
            
        break;
      }

      case 3: {
        setState(148);
        dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 = match(scqParser::NAME);

        	auto const & it = _localctx->procDefs->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""));
        	if (_localctx->objects->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : "")) == _localctx->objects->end()) {
        	  SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : "") + "\" isn't declared.");
        	}
        	
        break;
      }

      }
      setState(152);
      match(scqParser::EDGE_OP);
      setState(153);
      compositeOperand(_localctx->objects, _localctx->objDefs, &_localctx->paramNum, _localctx->funcParams, _localctx->depth);

      	if (_localctx->paramNum > _localctx->funcParams->size()) {
      	  SC_THROW_EXCEPTION(
      	    utils::ExceptionInvalidParams,
      	    "Expected " + std::to_string(_localctx->funcParams->size()) + " params. Gotten " + std::to_string(_localctx->paramNum) + ".");
      	}

      	if (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0 != nullptr)
      	{
      	  if (_localctx->objects->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0->getText() : "")) == _localctx->objects->end()) {
      		SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0->getText() : "") + "\" isn't declared.");
      	  }
      	  else {
      		SC_LOG_DEBUG("Define \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0->getText() : "") + "\" object");
      		_localctx->objDefs->push_back({ "assign", (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n0->getText() : ""), std::to_string(1), "" });
      		_localctx->objDefs->push_back({ "param", (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n1->getText() : ""), std::to_string(0), "" });
      	  }
      	}
      	
      break;
    }

    case 2: {
      setState(170);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(160);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == scqParser::NAME) {
          setState(157);
          dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 = match(scqParser::NAME);
          setState(158);
          match(scqParser::ASSIGN_OP);

          	if (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr) {
          	  if (_localctx->objects->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "")) == _localctx->objects->end()) {
          		SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "") + "\" isn't declared.");
          	  }
          	  else {
          		SC_LOG_DEBUG("Define \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "") + "\" object");
          		_localctx->objDefs->push_back({ "assign", (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : ""), std::to_string(1), "" });
          	  }
          	}
          	
        }
        setState(162);
        assignable(_localctx->objects, _localctx->objDefs, &_localctx->paramNum, _localctx->funcParams, _localctx->depth);
        break;
      }

      case 2: {
        setState(165);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == scqParser::NAME) {
          setState(163);
          dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 = match(scqParser::NAME);
          setState(164);
          match(scqParser::ASSIGN_OP);
        }
        setState(167);
        dynamic_cast<ObjectDefinitionContext *>(_localctx)->o1 = operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);

        	if (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr) {
        	  if (_localctx->objects->find((dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "")) == _localctx->objects->end()) {
        	    SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "") + "\" isn't declared.");
        	  }
        	  else {
        	    SC_LOG_DEBUG("Define \"" + (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : "") + "\" object");
        	    _localctx->objDefs->push_back({ "assign", (dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3 != nullptr ? dynamic_cast<ObjectDefinitionContext *>(_localctx)->n3->getText() : ""), std::to_string(1), "" });
        	    _localctx->objDefs->push_back({ "param", dynamic_cast<ObjectDefinitionContext *>(_localctx)->o1->name, std::to_string(0), "" });
        	  }
        	}
        	
        break;
      }

      }
      break;
    }

    }
    setState(174);
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

scqParser::OperationContext::OperationContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->procDefs = procDefs;
}

std::vector<tree::TerminalNode *> scqParser::OperationContext::EDGE_OP() {
  return getTokens(scqParser::EDGE_OP);
}

tree::TerminalNode* scqParser::OperationContext::EDGE_OP(size_t i) {
  return getToken(scqParser::EDGE_OP, i);
}

scqParser::TemplateCommandContext* scqParser::OperationContext::templateCommand() {
  return getRuleContext<scqParser::TemplateCommandContext>(0);
}

scqParser::SetOperationContext* scqParser::OperationContext::setOperation() {
  return getRuleContext<scqParser::SetOperationContext>(0);
}

tree::TerminalNode* scqParser::OperationContext::LEFT_CURL_BRACKET() {
  return getToken(scqParser::LEFT_CURL_BRACKET, 0);
}

std::vector<scqParser::OperationOperandContext *> scqParser::OperationContext::operationOperand() {
  return getRuleContexts<scqParser::OperationOperandContext>();
}

scqParser::OperationOperandContext* scqParser::OperationContext::operationOperand(size_t i) {
  return getRuleContext<scqParser::OperationOperandContext>(i);
}

tree::TerminalNode* scqParser::OperationContext::RIGHT_CURL_BRACKET() {
  return getToken(scqParser::RIGHT_CURL_BRACKET, 0);
}

std::vector<tree::TerminalNode *> scqParser::OperationContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::OperationContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}

tree::TerminalNode* scqParser::OperationContext::IF_OP() {
  return getToken(scqParser::IF_OP, 0);
}

std::vector<scqParser::TemplateExpressionContext *> scqParser::OperationContext::templateExpression() {
  return getRuleContexts<scqParser::TemplateExpressionContext>();
}

scqParser::TemplateExpressionContext* scqParser::OperationContext::templateExpression(size_t i) {
  return getRuleContext<scqParser::TemplateExpressionContext>(i);
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

std::vector<tree::TerminalNode *> scqParser::OperationContext::ELSE_OP() {
  return getTokens(scqParser::ELSE_OP);
}

tree::TerminalNode* scqParser::OperationContext::ELSE_OP(size_t i) {
  return getToken(scqParser::ELSE_OP, i);
}


size_t scqParser::OperationContext::getRuleIndex() const {
  return scqParser::RuleOperation;
}


scqParser::OperationContext* scqParser::operation(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  OperationContext *_localctx = _tracker.createInstance<OperationContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 14, scqParser::RuleOperation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::T__1:
      case scqParser::T__2:
      case scqParser::T__3:
      case scqParser::T__4:
      case scqParser::T__5:
      case scqParser::T__6:
      case scqParser::T__7:
      case scqParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(176);
        dynamic_cast<OperationContext *>(_localctx)->o1 = dynamic_cast<OperationContext *>(_localctx)->setOperationContext = setOperation(&_localctx->paramTypes);

        	SC_LOG_DEBUG("Define \"" + (dynamic_cast<OperationContext *>(_localctx)->setOperationContext != nullptr ? _input->getText(dynamic_cast<OperationContext *>(_localctx)->setOperationContext->start, dynamic_cast<OperationContext *>(_localctx)->setOperationContext->stop) : nullptr) + "\" operation");
        	_localctx->objDefs->push_back({ "call", (dynamic_cast<OperationContext *>(_localctx)->setOperationContext != nullptr ? _input->getText(dynamic_cast<OperationContext *>(_localctx)->setOperationContext->start, dynamic_cast<OperationContext *>(_localctx)->setOperationContext->stop) : nullptr), "", "" });

        	dynamic_cast<OperationContext *>(_localctx)->name =  (dynamic_cast<OperationContext *>(_localctx)->o1 != nullptr ? _input->getText(dynamic_cast<OperationContext *>(_localctx)->o1->start, dynamic_cast<OperationContext *>(_localctx)->o1->stop) : nullptr);
        	
        setState(179);
        match(scqParser::EDGE_OP);
        setState(193);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case scqParser::LEFT_CURL_BRACKET: {
            setState(180);
            match(scqParser::LEFT_CURL_BRACKET);

            	  _localctx->objDefs->push_back({ "param", "()", std::to_string(_localctx->depth), "" });
            	
            setState(182);
            operationOperand(_localctx->objects, _localctx->objDefs, &_localctx->paramNum, &_localctx->paramTypes, _localctx->depth + 1);
            setState(187);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == scqParser::COMMA) {
              setState(183);
              match(scqParser::COMMA);
              setState(184);
              operationOperand(_localctx->objects, _localctx->objDefs, &_localctx->paramNum, &_localctx->paramTypes, _localctx->depth + 1);
              setState(189);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(190);
            match(scqParser::RIGHT_CURL_BRACKET);
            break;
          }

          case scqParser::LEFT_SQUARE_BRACKET: {
            setState(192);
            templateCommand(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
            break;
          }

        default:
          throw NoViableAltException(this);
        }

            if (_localctx->paramNum > _localctx->paramTypes.size()) {
              SC_THROW_EXCEPTION(
                utils::ExceptionInvalidParams,
            	"Expected " + std::to_string(_localctx->paramTypes.size()) + " params. Gotten " + std::to_string(_localctx->paramNum) + ".");
            }
            
        break;
      }

      case scqParser::IF_OP: {
        enterOuterAlt(_localctx, 2);
        setState(197);
        dynamic_cast<OperationContext *>(_localctx)->if_opToken = match(scqParser::IF_OP);
        setState(198);
        match(scqParser::EDGE_OP);

        	  SC_LOG_DEBUG("Define \"" + (dynamic_cast<OperationContext *>(_localctx)->if_opToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->if_opToken->getText() : "") + "\" operation");
        	  _localctx->objDefs->push_back({ "call_if", "search", std::to_string(1), "" });
        	
        setState(200);
        templateExpression(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
        setState(201);
        match(scqParser::COMMA);
        setState(204);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(202);
          operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
          break;
        }

        case 2: {
          setState(203);
          objectDefinition(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
          break;
        }

        }
        setState(213);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(206);
            match(scqParser::COMMA);
            setState(209);
            _errHandler->sync(this);
            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
            case 1: {
              setState(207);
              operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
              break;
            }

            case 2: {
              setState(208);
              objectDefinition(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
              break;
            }

            } 
          }
          setState(215);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
        }
        setState(238);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == scqParser::COMMA) {
          setState(216);
          match(scqParser::COMMA);
          setState(217);
          dynamic_cast<OperationContext *>(_localctx)->else_opToken = match(scqParser::ELSE_OP);
          setState(218);
          match(scqParser::EDGE_OP);

          	  SC_LOG_DEBUG("Define \"" + (dynamic_cast<OperationContext *>(_localctx)->if_opToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->if_opToken->getText() : "") + "\" operation");
          	  _localctx->objDefs->push_back({ "call_if", "search", std::to_string(1), "" });
          	
          setState(220);
          templateExpression(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
          setState(221);
          match(scqParser::COMMA);
          setState(224);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
          case 1: {
            setState(222);
            operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
            break;
          }

          case 2: {
            setState(223);
            objectDefinition(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
            break;
          }

          }
          setState(233);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(226);
              match(scqParser::COMMA);
              setState(229);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
              case 1: {
                setState(227);
                operation(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
                break;
              }

              case 2: {
                setState(228);
                objectDefinition(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
                break;
              }

              } 
            }
            setState(235);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
          }
          setState(240);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }

        	  _localctx->objDefs->push_back({ "end", (dynamic_cast<OperationContext *>(_localctx)->else_opToken != nullptr ? dynamic_cast<OperationContext *>(_localctx)->else_opToken->getText() : ""), "", "" });
        	
        setState(242);
        match(scqParser::T__0);
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

scqParser::CompositeOperandContext::CompositeOperandContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->paramNum = paramNum;
  this->params = params;
  this->depth = depth;
}

tree::TerminalNode* scqParser::CompositeOperandContext::LEFT_CURL_BRACKET() {
  return getToken(scqParser::LEFT_CURL_BRACKET, 0);
}

tree::TerminalNode* scqParser::CompositeOperandContext::RIGHT_CURL_BRACKET() {
  return getToken(scqParser::RIGHT_CURL_BRACKET, 0);
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


scqParser::CompositeOperandContext* scqParser::compositeOperand(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth) {
  CompositeOperandContext *_localctx = _tracker.createInstance<CompositeOperandContext>(_ctx, getState(), objects, objDefs, paramNum, params, depth);
  enterRule(_localctx, 16, scqParser::RuleCompositeOperand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(scqParser::LEFT_CURL_BRACKET);

    	  _localctx->objDefs->push_back({ "param", "()", std::to_string(depth), "" });
    	
    setState(249);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::STRING)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(248);
      operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
    }
    setState(255);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(251);
      match(scqParser::COMMA);
      setState(252);
      operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(258);
    match(scqParser::RIGHT_CURL_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignableContext ------------------------------------------------------------------

scqParser::AssignableContext::AssignableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::AssignableContext::AssignableContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->paramNum = paramNum;
  this->params = params;
  this->depth = depth;
}

tree::TerminalNode* scqParser::AssignableContext::LEFT_CURL_BRACKET() {
  return getToken(scqParser::LEFT_CURL_BRACKET, 0);
}

tree::TerminalNode* scqParser::AssignableContext::RIGHT_CURL_BRACKET() {
  return getToken(scqParser::RIGHT_CURL_BRACKET, 0);
}

std::vector<scqParser::OperandContext *> scqParser::AssignableContext::operand() {
  return getRuleContexts<scqParser::OperandContext>();
}

scqParser::OperandContext* scqParser::AssignableContext::operand(size_t i) {
  return getRuleContext<scqParser::OperandContext>(i);
}

std::vector<tree::TerminalNode *> scqParser::AssignableContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::AssignableContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}

tree::TerminalNode* scqParser::AssignableContext::LEFT_FIGURE_BRACKET() {
  return getToken(scqParser::LEFT_FIGURE_BRACKET, 0);
}

tree::TerminalNode* scqParser::AssignableContext::RIGHT_FIGURE_BRACKET() {
  return getToken(scqParser::RIGHT_FIGURE_BRACKET, 0);
}


size_t scqParser::AssignableContext::getRuleIndex() const {
  return scqParser::RuleAssignable;
}


scqParser::AssignableContext* scqParser::assignable(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth) {
  AssignableContext *_localctx = _tracker.createInstance<AssignableContext>(_ctx, getState(), objects, objDefs, paramNum, params, depth);
  enterRule(_localctx, 18, scqParser::RuleAssignable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::LEFT_CURL_BRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(260);
        match(scqParser::LEFT_CURL_BRACKET);

        	  _localctx->objDefs->push_back({ "param", "()", std::to_string(depth), "" });
        	
        setState(263);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << scqParser::LEFT_FIGURE_BRACKET)
          | (1ULL << scqParser::LEFT_CURL_BRACKET)
          | (1ULL << scqParser::STRING)
          | (1ULL << scqParser::NAME))) != 0)) {
          setState(262);
          operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
        }
        setState(269);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == scqParser::COMMA) {
          setState(265);
          match(scqParser::COMMA);
          setState(266);
          operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
          setState(271);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(272);
        match(scqParser::RIGHT_CURL_BRACKET);
        break;
      }

      case scqParser::LEFT_FIGURE_BRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(273);
        match(scqParser::LEFT_FIGURE_BRACKET);

        	  _localctx->objDefs->push_back({ "param", "{}", std::to_string(depth), "" });
        	
        setState(276);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << scqParser::LEFT_FIGURE_BRACKET)
          | (1ULL << scqParser::LEFT_CURL_BRACKET)
          | (1ULL << scqParser::STRING)
          | (1ULL << scqParser::NAME))) != 0)) {
          setState(275);
          operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
        }
        setState(282);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == scqParser::COMMA) {
          setState(278);
          match(scqParser::COMMA);
          setState(279);
          operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
          setState(284);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(285);
        match(scqParser::RIGHT_FIGURE_BRACKET);
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

//----------------- OperationOperandContext ------------------------------------------------------------------

scqParser::OperationOperandContext::OperationOperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scqParser::OperationOperandContext::OperationOperandContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, std::vector<std::vector<std::string>> * params, size_t depth)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->paramNum = paramNum;
  this->params = params;
  this->depth = depth;
}

tree::TerminalNode* scqParser::OperationOperandContext::NAME() {
  return getToken(scqParser::NAME, 0);
}

tree::TerminalNode* scqParser::OperationOperandContext::STRING() {
  return getToken(scqParser::STRING, 0);
}


size_t scqParser::OperationOperandContext::getRuleIndex() const {
  return scqParser::RuleOperationOperand;
}


scqParser::OperationOperandContext* scqParser::operationOperand(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,std::vector<std::vector<std::string>> * params,size_t depth) {
  OperationOperandContext *_localctx = _tracker.createInstance<OperationOperandContext>(_ctx, getState(), objects, objDefs, paramNum, params, depth);
  enterRule(_localctx, 20, scqParser::RuleOperationOperand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(292);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(288);
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
        	        "Unexpected param \"" + (dynamic_cast<OperationOperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->nameToken->getText() : "") + "\" with type \"" + type + "\" in function call." \
        	        "Expected param with type \"" + expectedTypes.at(0) + "\".");
        	    }
              }
              ++(*_localctx->paramNum);
            }
            _localctx->objDefs->push_back({ "param", (dynamic_cast<OperationOperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->nameToken->getText() : ""), std::to_string(_localctx->depth), "" });
            
        break;
      }

      case scqParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(290);
        dynamic_cast<OperationOperandContext *>(_localctx)->stringToken = match(scqParser::STRING);

        	if (paramNum != nullptr && params != nullptr) {
              if (*paramNum < params->size()) {
            	std::vector<std::string> & expectedTypes = _localctx->params->at(*_localctx->paramNum);
            	if (std::find(expectedTypes.begin(), expectedTypes.end(), "string") == expectedTypes.end()) {
            	  SC_THROW_EXCEPTION(
            	    utils::ExceptionInvalidParams,
            	    "Unexpected param \"" + (dynamic_cast<OperationOperandContext *>(_localctx)->stringToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->stringToken->getText() : "") + "\" with type \"string\" in function call." \
            	    "Expected param with type \"" + expectedTypes.at(0) + "\".");
            	}
              }
              ++(*_localctx->paramNum);
            }
            _localctx->objDefs->push_back({ "param", (dynamic_cast<OperationOperandContext *>(_localctx)->stringToken != nullptr ? dynamic_cast<OperationOperandContext *>(_localctx)->stringToken->getText() : ""), std::to_string(_localctx->depth), "" });
            
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

scqParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->paramNum = paramNum;
  this->params = params;
  this->depth = depth;
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


size_t scqParser::OperandContext::getRuleIndex() const {
  return scqParser::RuleOperand;
}


scqParser::OperandContext* scqParser::operand(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth) {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState(), objects, objDefs, paramNum, params, depth);
  enterRule(_localctx, 22, scqParser::RuleOperand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(299);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(294);
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
        	        "Unexpected param \"" + (dynamic_cast<OperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperandContext *>(_localctx)->nameToken->getText() : "") + "\" with type \"" + type + "\" in function call." \
        	        "Expected param with type \"" + expectedType + "\".");
        	    }
              }
              ++(*_localctx->paramNum);
            }

            _localctx->objDefs->push_back({ "param", (dynamic_cast<OperandContext *>(_localctx)->nameToken != nullptr ? dynamic_cast<OperandContext *>(_localctx)->nameToken->getText() : ""), std::to_string(_localctx->depth), "" });
        	
        break;
      }

      case scqParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(296);
        match(scqParser::STRING);
        break;
      }

      case scqParser::LEFT_CURL_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(297);
        orientedSet(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth);
        break;
      }

      case scqParser::LEFT_FIGURE_BRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(298);
        nonOrientedSet(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth);
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

scqParser::NonOrientedSetContext::NonOrientedSetContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->paramNum = paramNum;
  this->params = params;
  this->depth = depth;
}

tree::TerminalNode* scqParser::NonOrientedSetContext::LEFT_FIGURE_BRACKET() {
  return getToken(scqParser::LEFT_FIGURE_BRACKET, 0);
}

tree::TerminalNode* scqParser::NonOrientedSetContext::RIGHT_FIGURE_BRACKET() {
  return getToken(scqParser::RIGHT_FIGURE_BRACKET, 0);
}

std::vector<scqParser::OperandContext *> scqParser::NonOrientedSetContext::operand() {
  return getRuleContexts<scqParser::OperandContext>();
}

scqParser::OperandContext* scqParser::NonOrientedSetContext::operand(size_t i) {
  return getRuleContext<scqParser::OperandContext>(i);
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


scqParser::NonOrientedSetContext* scqParser::nonOrientedSet(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth) {
  NonOrientedSetContext *_localctx = _tracker.createInstance<NonOrientedSetContext>(_ctx, getState(), objects, objDefs, paramNum, params, depth);
  enterRule(_localctx, 24, scqParser::RuleNonOrientedSet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
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
     	

    	  _localctx->objDefs->push_back({ "param", "{}", std::to_string(depth), "" });
    	
    setState(305);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::STRING)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(304);
      operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
    }
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(307);
      match(scqParser::COMMA);
      setState(308);
      operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
      setState(313);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(314);
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

scqParser::OrientedSetContext::OrientedSetContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, size_t * paramNum, ProcDefinitionContext::ProcedureParams * params, size_t depth)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->paramNum = paramNum;
  this->params = params;
  this->depth = depth;
}

tree::TerminalNode* scqParser::OrientedSetContext::LEFT_CURL_BRACKET() {
  return getToken(scqParser::LEFT_CURL_BRACKET, 0);
}

tree::TerminalNode* scqParser::OrientedSetContext::RIGHT_CURL_BRACKET() {
  return getToken(scqParser::RIGHT_CURL_BRACKET, 0);
}

std::vector<scqParser::OperandContext *> scqParser::OrientedSetContext::operand() {
  return getRuleContexts<scqParser::OperandContext>();
}

scqParser::OperandContext* scqParser::OrientedSetContext::operand(size_t i) {
  return getRuleContext<scqParser::OperandContext>(i);
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


scqParser::OrientedSetContext* scqParser::orientedSet(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,size_t * paramNum,ProcDefinitionContext::ProcedureParams * params,size_t depth) {
  OrientedSetContext *_localctx = _tracker.createInstance<OrientedSetContext>(_ctx, getState(), objects, objDefs, paramNum, params, depth);
  enterRule(_localctx, 26, scqParser::RuleOrientedSet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
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
        

    	  _localctx->objDefs->push_back({ "param", "()", std::to_string(depth), "" });
    	
    setState(320);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << scqParser::LEFT_FIGURE_BRACKET)
      | (1ULL << scqParser::LEFT_CURL_BRACKET)
      | (1ULL << scqParser::STRING)
      | (1ULL << scqParser::NAME))) != 0)) {
      setState(319);
      operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
    }
    setState(326);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(322);
      match(scqParser::COMMA);
      setState(323);
      operand(_localctx->objects, _localctx->objDefs, _localctx->paramNum, _localctx->params, _localctx->depth + 1);
      setState(328);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(329);
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

scqParser::TemplateCommandContext::TemplateCommandContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->procDefs = procDefs;
}

scqParser::TemplateExpressionContext* scqParser::TemplateCommandContext::templateExpression() {
  return getRuleContext<scqParser::TemplateExpressionContext>(0);
}

scqParser::CommandTemplateResultContext* scqParser::TemplateCommandContext::commandTemplateResult() {
  return getRuleContext<scqParser::CommandTemplateResultContext>(0);
}


size_t scqParser::TemplateCommandContext::getRuleIndex() const {
  return scqParser::RuleTemplateCommand;
}


scqParser::TemplateCommandContext* scqParser::templateCommand(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  TemplateCommandContext *_localctx = _tracker.createInstance<TemplateCommandContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 28, scqParser::RuleTemplateCommand);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    templateExpression(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scqParser::AS_OP) {
      setState(332);
      commandTemplateResult(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
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

scqParser::TemplateExpressionContext::TemplateExpressionContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->procDefs = procDefs;
}

tree::TerminalNode* scqParser::TemplateExpressionContext::LEFT_SQUARE_BRACKET() {
  return getToken(scqParser::LEFT_SQUARE_BRACKET, 0);
}

std::vector<scqParser::CommandTemplateContext *> scqParser::TemplateExpressionContext::commandTemplate() {
  return getRuleContexts<scqParser::CommandTemplateContext>();
}

scqParser::CommandTemplateContext* scqParser::TemplateExpressionContext::commandTemplate(size_t i) {
  return getRuleContext<scqParser::CommandTemplateContext>(i);
}

tree::TerminalNode* scqParser::TemplateExpressionContext::RIGHT_SQUARE_BRACKET() {
  return getToken(scqParser::RIGHT_SQUARE_BRACKET, 0);
}

std::vector<tree::TerminalNode *> scqParser::TemplateExpressionContext::COMMA() {
  return getTokens(scqParser::COMMA);
}

tree::TerminalNode* scqParser::TemplateExpressionContext::COMMA(size_t i) {
  return getToken(scqParser::COMMA, i);
}


size_t scqParser::TemplateExpressionContext::getRuleIndex() const {
  return scqParser::RuleTemplateExpression;
}


scqParser::TemplateExpressionContext* scqParser::templateExpression(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  TemplateExpressionContext *_localctx = _tracker.createInstance<TemplateExpressionContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 30, scqParser::RuleTemplateExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(scqParser::LEFT_SQUARE_BRACKET);
    setState(336);
    commandTemplate(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
    setState(341);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(337);
      match(scqParser::COMMA);
      setState(338);
      commandTemplate(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
      setState(343);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(344);
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

scqParser::CommandTemplateContext::CommandTemplateContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->procDefs = procDefs;
}

tree::TerminalNode* scqParser::CommandTemplateContext::EDGE_OP() {
  return getToken(scqParser::EDGE_OP, 0);
}

std::vector<scqParser::TemplateParamContext *> scqParser::CommandTemplateContext::templateParam() {
  return getRuleContexts<scqParser::TemplateParamContext>();
}

scqParser::TemplateParamContext* scqParser::CommandTemplateContext::templateParam(size_t i) {
  return getRuleContext<scqParser::TemplateParamContext>(i);
}


size_t scqParser::CommandTemplateContext::getRuleIndex() const {
  return scqParser::RuleCommandTemplate;
}


scqParser::CommandTemplateContext* scqParser::commandTemplate(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  CommandTemplateContext *_localctx = _tracker.createInstance<CommandTemplateContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 32, scqParser::RuleCommandTemplate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    dynamic_cast<CommandTemplateContext *>(_localctx)->source = templateParam(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
    setState(347);
    match(scqParser::EDGE_OP);
    setState(348);
    dynamic_cast<CommandTemplateContext *>(_localctx)->target = templateParam(_localctx->objects, _localctx->objDefs, _localctx->procDefs);

    	_localctx->objDefs->push_back({ "param", dynamic_cast<CommandTemplateContext *>(_localctx)->source->param, "0", "" });
    	_localctx->objDefs->push_back({ "param", dynamic_cast<CommandTemplateContext *>(_localctx)->target->param, "0", "" });
    	
   
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

scqParser::CommandTemplateResultContext::CommandTemplateResultContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->procDefs = procDefs;
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


scqParser::CommandTemplateResultContext* scqParser::commandTemplateResult(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  CommandTemplateResultContext *_localctx = _tracker.createInstance<CommandTemplateResultContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 34, scqParser::RuleCommandTemplateResult);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    match(scqParser::AS_OP);
    setState(352);
    match(scqParser::LEFT_SQUARE_BRACKET);
    setState(353);
    templateParam(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
    setState(358);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == scqParser::COMMA) {
      setState(354);
      match(scqParser::COMMA);
      setState(355);
      templateParam(_localctx->objects, _localctx->objDefs, _localctx->procDefs);
      setState(360);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(361);
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

scqParser::TemplateParamContext::TemplateParamContext(ParserRuleContext *parent, size_t invokingState, ProgramContext::Objects * objects, ProgramContext::ObjectsDefinitions * objDefs, ProgramContext::ProcedureDefinitions * procDefs)
  : ParserRuleContext(parent, invokingState) {
  this->objects = objects;
  this->objDefs = objDefs;
  this->procDefs = procDefs;
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


scqParser::TemplateParamContext* scqParser::templateParam(ProgramContext::Objects * objects,ProgramContext::ObjectsDefinitions * objDefs,ProgramContext::ProcedureDefinitions * procDefs) {
  TemplateParamContext *_localctx = _tracker.createInstance<TemplateParamContext>(_ctx, getState(), objects, objDefs, procDefs);
  enterRule(_localctx, 36, scqParser::RuleTemplateParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(372);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::OBJECT_TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(363);
        dynamic_cast<TemplateParamContext *>(_localctx)->n1 = match(scqParser::OBJECT_TYPE);

            dynamic_cast<TemplateParamContext *>(_localctx)->param =  (dynamic_cast<TemplateParamContext *>(_localctx)->n1 != nullptr ? dynamic_cast<TemplateParamContext *>(_localctx)->n1->getText() : "");
            
        break;
      }

      case scqParser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(365);
        dynamic_cast<TemplateParamContext *>(_localctx)->n1 = match(scqParser::NAME);

        	dynamic_cast<TemplateParamContext *>(_localctx)->param =  (dynamic_cast<TemplateParamContext *>(_localctx)->n1 != nullptr ? dynamic_cast<TemplateParamContext *>(_localctx)->n1->getText() : "");

        	if (dynamic_cast<TemplateParamContext *>(_localctx)->n1 != nullptr)
        	{
        	  auto const & it = _localctx->procDefs->find((dynamic_cast<TemplateParamContext *>(_localctx)->n1 != nullptr ? dynamic_cast<TemplateParamContext *>(_localctx)->n1->getText() : ""));
        	  if (_localctx->objects->find((dynamic_cast<TemplateParamContext *>(_localctx)->n1 != nullptr ? dynamic_cast<TemplateParamContext *>(_localctx)->n1->getText() : "")) == _localctx->objects->end()) {
        	    SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "The object \"" + (dynamic_cast<TemplateParamContext *>(_localctx)->n1 != nullptr ? dynamic_cast<TemplateParamContext *>(_localctx)->n1->getText() : "") + "\" isn't declared.");
        	  }
        	}
        	
        break;
      }

      case scqParser::LEFT_TRIANGLE_BRACKET: {
        enterOuterAlt(_localctx, 3);
        setState(367);
        match(scqParser::LEFT_TRIANGLE_BRACKET);
        setState(368);
        dynamic_cast<TemplateParamContext *>(_localctx)->n2 = match(scqParser::NAME);
        setState(369);
        match(scqParser::RIGHT_TRIANGLE_BRACKET);

        	dynamic_cast<TemplateParamContext *>(_localctx)->param =  "<" + (dynamic_cast<TemplateParamContext *>(_localctx)->n2 != nullptr ? dynamic_cast<TemplateParamContext *>(_localctx)->n2->getText() : "") + ">";
        	objects->insert({ (dynamic_cast<TemplateParamContext *>(_localctx)->n2 != nullptr ? dynamic_cast<TemplateParamContext *>(_localctx)->n2->getText() : ""), "set" });
        	
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


scqParser::SetOperationContext* scqParser::setOperation(std::vector<std::vector<std::string>> * paramTypes) {
  SetOperationContext *_localctx = _tracker.createInstance<SetOperationContext>(_ctx, getState(), paramTypes);
  enterRule(_localctx, 38, scqParser::RuleSetOperation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scqParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(374);
        match(scqParser::T__1);

        	paramTypes->push_back({ "set" });
        	paramTypes->push_back({ "set" });
        	
        break;
      }

      case scqParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(376);
        match(scqParser::T__2);

            paramTypes->push_back({ "set" });
            paramTypes->push_back({ "set" });
            
        break;
      }

      case scqParser::T__3: {
        enterOuterAlt(_localctx, 3);
        setState(378);
        match(scqParser::T__3);

        	paramTypes->push_back({ "set" });
        	paramTypes->push_back({ "set" });
            
        break;
      }

      case scqParser::T__4: {
        enterOuterAlt(_localctx, 4);
        setState(380);
        match(scqParser::T__4);

            paramTypes->push_back({ "set", "tuple", "terminal" });
            
        break;
      }

      case scqParser::T__5: {
        enterOuterAlt(_localctx, 5);
        setState(382);
        match(scqParser::T__5);

        	paramTypes->push_back({ "set", "tuple", "terminal" });
            paramTypes->push_back({ "string" });
            
        break;
      }

      case scqParser::T__6: {
        enterOuterAlt(_localctx, 6);
        setState(384);
        match(scqParser::T__6);

        	paramTypes->push_back({ "string" });
        	
        break;
      }

      case scqParser::T__7: {
        enterOuterAlt(_localctx, 7);
        setState(386);
        match(scqParser::T__7);

            paramTypes->push_back({ "set", "tuple", "terminal" });
            
        break;
      }

      case scqParser::T__8: {
        enterOuterAlt(_localctx, 8);
        setState(388);
        match(scqParser::T__8);

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
  "assignable", "operationOperand", "operand", "nonOrientedSet", "orientedSet", 
  "templateCommand", "templateExpression", "commandTemplate", "commandTemplateResult", 
  "templateParam", "setOperation"
};

std::vector<std::string> scqParser::_literalNames = {
  "", "'endif'", "'intersect'", "'complement'", "'unite'", "'remove'", "'set_idtf'", 
  "'resolve_idtf'", "'dump'", "'return'", "'->'", "':='", "'as'", "'if'", 
  "'elif'", "'<'", "'>'", "'['", "']'", "'{'", "'}'", "'('", "')'", "','", 
  "';'", "'procedure'"
};

std::vector<std::string> scqParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "EDGE_OP", "ASSIGN_OP", "AS_OP", 
  "IF_OP", "ELSE_OP", "LEFT_TRIANGLE_BRACKET", "RIGHT_TRIANGLE_BRACKET", 
  "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "LEFT_FIGURE_BRACKET", 
  "RIGHT_FIGURE_BRACKET", "LEFT_CURL_BRACKET", "RIGHT_CURL_BRACKET", "COMMA", 
  "SEMICOLON", "PROCEDURE_TYPE", "OBJECT_TYPE", "STRING", "NAME", "LETTER", 
  "DIGIT", "WS", "SL_COMMENT"
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
    0x3, 0x22, 0x18b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x3, 0x2, 0x7, 0x2, 0x2c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x2f, 
    0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x32, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x35, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x40, 0xa, 0x3, 0xc, 0x3, 0xe, 
    0x3, 0x43, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x49, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0x59, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5c, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x61, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x64, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x68, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x6b, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x72, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x75, 0xb, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7c, 
    0xa, 0x7, 0x7, 0x7, 0x7e, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x81, 0xb, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0x89, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x8c, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x93, 0xa, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x99, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0xa3, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xa8, 0xa, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xad, 0xa, 0x8, 0x5, 0x8, 0xaf, 
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xbc, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0xbf, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0xc4, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xcf, 0xa, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xd4, 0xa, 0x9, 0x7, 0x9, 0xd6, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xd9, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xe3, 
    0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xe8, 0xa, 0x9, 0x7, 
    0x9, 0xea, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xed, 0xb, 0x9, 0x7, 0x9, 0xef, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xf2, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0xf7, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0xfc, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x100, 0xa, 0xa, 0xc, 
    0xa, 0xe, 0xa, 0x103, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0x10a, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x10e, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x111, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0x117, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
    0x11b, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x11e, 0xb, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0x121, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x127, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x12e, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0x134, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x138, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0x13b, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x143, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 
    0xf, 0x147, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x14a, 0xb, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x150, 0xa, 0x10, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x156, 0xa, 0x11, 0xc, 0x11, 
    0xe, 0x11, 0x159, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x7, 0x13, 0x167, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 
    0x16a, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0x177, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
    0x189, 0xa, 0x15, 0x3, 0x15, 0x2, 0x2, 0x16, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2, 0x2, 0x2, 0x1af, 0x2, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x38, 0x3, 0x2, 0x2, 0x2, 0x6, 0x48, 0x3, 0x2, 0x2, 0x2, 0x8, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x73, 0x3, 0x2, 0x2, 0x2, 0xc, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xae, 0x3, 0x2, 0x2, 0x2, 0x10, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x14, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x126, 0x3, 0x2, 0x2, 0x2, 0x18, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x12f, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x14d, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x151, 0x3, 0x2, 0x2, 0x2, 0x22, 0x15c, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x161, 0x3, 0x2, 0x2, 0x2, 0x26, 0x176, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x188, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x5, 0x4, 0x3, 
    0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 
    0x5, 0x6, 0x4, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x37, 0x5, 0xa, 0x6, 0x2, 0x37, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x39, 0x7, 0x1b, 0x2, 0x2, 0x39, 0x3a, 0x7, 0xc, 0x2, 0x2, 0x3a, 
    0x3b, 0x7, 0x1e, 0x2, 0x2, 0x3b, 0x41, 0x8, 0x3, 0x1, 0x2, 0x3c, 0x3d, 
    0x7, 0x19, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x1e, 0x2, 0x2, 0x3e, 0x40, 0x8, 
    0x3, 0x1, 0x2, 0x3f, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x44, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x45, 0x7, 0x1a, 0x2, 0x2, 0x45, 0x5, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x7, 0x1b, 0x2, 0x2, 0x47, 0x49, 0x7, 0xc, 0x2, 0x2, 0x48, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x1e, 0x2, 0x2, 0x4b, 0x4c, 0x8, 0x4, 
    0x1, 0x2, 0x4c, 0x4d, 0x7, 0xd, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0x8, 0x5, 
    0x2, 0x4e, 0x4f, 0x7, 0x19, 0x2, 0x2, 0x4f, 0x50, 0x5, 0xa, 0x6, 0x2, 
    0x50, 0x51, 0x8, 0x4, 0x1, 0x2, 0x51, 0x52, 0x7, 0x1a, 0x2, 0x2, 0x52, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x53, 0x5a, 0x7, 0x17, 0x2, 0x2, 0x54, 0x55, 
    0x7, 0x1c, 0x2, 0x2, 0x55, 0x56, 0x7, 0xc, 0x2, 0x2, 0x56, 0x57, 0x7, 
    0x1e, 0x2, 0x2, 0x57, 0x59, 0x8, 0x5, 0x1, 0x2, 0x58, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x62, 0x7, 0x19, 0x2, 0x2, 0x5e, 
    0x5f, 0x7, 0x1c, 0x2, 0x2, 0x5f, 0x61, 0x7, 0xc, 0x2, 0x2, 0x60, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x61, 0x64, 0x3, 0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 0x65, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0x1e, 0x2, 
    0x2, 0x66, 0x68, 0x8, 0x5, 0x1, 0x2, 0x67, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 
    0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x18, 0x2, 0x2, 0x6d, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x72, 0x5, 0xc, 0x7, 0x2, 0x6f, 0x72, 0x5, 0xe, 
    0x8, 0x2, 0x70, 0x72, 0x5, 0x10, 0x9, 0x2, 0x71, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x75, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0xb, 0x3, 0x2, 0x2, 0x2, 0x75, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x7f, 0x7, 0x1c, 0x2, 0x2, 0x77, 0x7b, 0x7, 
    0x19, 0x2, 0x2, 0x78, 0x7c, 0x7, 0x1c, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x1e, 
    0x2, 0x2, 0x7a, 0x7c, 0x8, 0x7, 0x1, 0x2, 0x7b, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x7d, 0x77, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 
    0xc, 0x2, 0x2, 0x83, 0x84, 0x7, 0x1e, 0x2, 0x2, 0x84, 0x8a, 0x8, 0x7, 
    0x1, 0x2, 0x85, 0x86, 0x7, 0x19, 0x2, 0x2, 0x86, 0x87, 0x7, 0x1e, 0x2, 
    0x2, 0x87, 0x89, 0x8, 0x7, 0x1, 0x2, 0x88, 0x85, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x1a, 0x2, 0x2, 0x8e, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x99, 0x7, 0x1c, 0x2, 0x2, 0x90, 0x91, 0x7, 0x1e, 
    0x2, 0x2, 0x91, 0x93, 0x7, 0xd, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x95, 0x7, 0x1e, 0x2, 0x2, 0x95, 0x99, 0x8, 0x8, 0x1, 0x2, 0x96, 
    0x97, 0x7, 0x1e, 0x2, 0x2, 0x97, 0x99, 0x8, 0x8, 0x1, 0x2, 0x98, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x92, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0xc, 
    0x2, 0x2, 0x9b, 0x9c, 0x5, 0x12, 0xa, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x9e, 0x8, 0x8, 0x1, 0x2, 0x9e, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa0, 0x7, 0x1e, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0xd, 0x2, 0x2, 0xa1, 
    0xa3, 0x8, 0x8, 0x1, 0x2, 0xa2, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xad, 0x5, 
    0x14, 0xb, 0x2, 0xa5, 0xa6, 0x7, 0x1e, 0x2, 0x2, 0xa6, 0xa8, 0x7, 0xd, 
    0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x10, 0x9, 0x2, 
    0xaa, 0xab, 0x8, 0x8, 0x1, 0x2, 0xab, 0xad, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xad, 0xaf, 
    0x3, 0x2, 0x2, 0x2, 0xae, 0x98, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x1a, 
    0x2, 0x2, 0xb1, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x5, 0x28, 0x15, 
    0x2, 0xb3, 0xb4, 0x8, 0x9, 0x1, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xc3, 0x7, 0xc, 0x2, 0x2, 0xb6, 0xb7, 0x7, 0x17, 0x2, 0x2, 0xb7, 
    0xb8, 0x8, 0x9, 0x1, 0x2, 0xb8, 0xbd, 0x5, 0x16, 0xc, 0x2, 0xb9, 0xba, 
    0x7, 0x19, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x16, 0xc, 0x2, 0xbb, 0xb9, 0x3, 
    0x2, 0x2, 0x2, 0xbc, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x18, 0x2, 0x2, 
    0xc1, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc4, 0x5, 0x1e, 0x10, 0x2, 0xc3, 
    0xb6, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 
    0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x8, 0x9, 0x1, 0x2, 0xc6, 0xf7, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0xf, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0xc, 
    0x2, 0x2, 0xc9, 0xca, 0x8, 0x9, 0x1, 0x2, 0xca, 0xcb, 0x5, 0x20, 0x11, 
    0x2, 0xcb, 0xce, 0x7, 0x19, 0x2, 0x2, 0xcc, 0xcf, 0x5, 0x10, 0x9, 0x2, 
    0xcd, 0xcf, 0x5, 0xe, 0x8, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd3, 
    0x7, 0x19, 0x2, 0x2, 0xd1, 0xd4, 0x5, 0x10, 0x9, 0x2, 0xd2, 0xd4, 0x5, 
    0xe, 0x8, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd0, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x19, 0x2, 0x2, 0xdb, 0xdc, 
    0x7, 0x10, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0xc, 0x2, 0x2, 0xdd, 0xde, 0x8, 
    0x9, 0x1, 0x2, 0xde, 0xdf, 0x5, 0x20, 0x11, 0x2, 0xdf, 0xe2, 0x7, 0x19, 
    0x2, 0x2, 0xe0, 0xe3, 0x5, 0x10, 0x9, 0x2, 0xe1, 0xe3, 0x5, 0xe, 0x8, 
    0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 0x7, 0x19, 0x2, 0x2, 0xe5, 
    0xe8, 0x5, 0x10, 0x9, 0x2, 0xe6, 0xe8, 0x5, 0xe, 0x8, 0x2, 0xe7, 0xe5, 
    0x3, 0x2, 0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0xe9, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xea, 0xed, 0x3, 0x2, 
    0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xef, 0x3, 0x2, 0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 
    0xee, 0xda, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf3, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x8, 
    0x9, 0x1, 0x2, 0xf4, 0xf5, 0x7, 0x3, 0x2, 0x2, 0xf5, 0xf7, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0x11, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x17, 0x2, 0x2, 
    0xf9, 0xfb, 0x8, 0xa, 0x1, 0x2, 0xfa, 0xfc, 0x5, 0x18, 0xd, 0x2, 0xfb, 
    0xfa, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x101, 
    0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x19, 0x2, 0x2, 0xfe, 0x100, 0x5, 
    0x18, 0xd, 0x2, 0xff, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0x103, 0x3, 0x2, 
    0x2, 0x2, 0x101, 0xff, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x102, 0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x105, 0x7, 0x18, 0x2, 0x2, 0x105, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x107, 0x7, 0x17, 0x2, 0x2, 0x107, 0x109, 0x8, 0xb, 0x1, 
    0x2, 0x108, 0x10a, 0x5, 0x18, 0xd, 0x2, 0x109, 0x108, 0x3, 0x2, 0x2, 
    0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10f, 0x3, 0x2, 0x2, 
    0x2, 0x10b, 0x10c, 0x7, 0x19, 0x2, 0x2, 0x10c, 0x10e, 0x5, 0x18, 0xd, 
    0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x111, 0x3, 0x2, 0x2, 
    0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x3, 0x2, 0x2, 
    0x2, 0x110, 0x112, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x121, 0x7, 0x18, 0x2, 0x2, 0x113, 0x114, 0x7, 0x15, 0x2, 
    0x2, 0x114, 0x116, 0x8, 0xb, 0x1, 0x2, 0x115, 0x117, 0x5, 0x18, 0xd, 
    0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x117, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x7, 0x19, 0x2, 
    0x2, 0x119, 0x11b, 0x5, 0x18, 0xd, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x121, 0x7, 0x16, 0x2, 
    0x2, 0x120, 0x106, 0x3, 0x2, 0x2, 0x2, 0x120, 0x113, 0x3, 0x2, 0x2, 
    0x2, 0x121, 0x15, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x7, 0x1e, 0x2, 
    0x2, 0x123, 0x127, 0x8, 0xc, 0x1, 0x2, 0x124, 0x125, 0x7, 0x1d, 0x2, 
    0x2, 0x125, 0x127, 0x8, 0xc, 0x1, 0x2, 0x126, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 0x127, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x129, 0x7, 0x1e, 0x2, 0x2, 0x129, 0x12e, 0x8, 0xd, 0x1, 0x2, 
    0x12a, 0x12e, 0x7, 0x1d, 0x2, 0x2, 0x12b, 0x12e, 0x5, 0x1c, 0xf, 0x2, 
    0x12c, 0x12e, 0x5, 0x1a, 0xe, 0x2, 0x12d, 0x128, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 
    0x12d, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x19, 0x3, 0x2, 0x2, 0x2, 0x12f, 
    0x130, 0x7, 0x15, 0x2, 0x2, 0x130, 0x131, 0x8, 0xe, 0x1, 0x2, 0x131, 
    0x133, 0x8, 0xe, 0x1, 0x2, 0x132, 0x134, 0x5, 0x18, 0xd, 0x2, 0x133, 
    0x132, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x3, 0x2, 0x2, 0x2, 0x134, 
    0x139, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x7, 0x19, 0x2, 0x2, 0x136, 
    0x138, 0x5, 0x18, 0xd, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x13b, 0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 
    0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13b, 
    0x139, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0x7, 0x16, 0x2, 0x2, 0x13d, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x7, 0x17, 0x2, 0x2, 0x13f, 
    0x140, 0x8, 0xf, 0x1, 0x2, 0x140, 0x142, 0x8, 0xf, 0x1, 0x2, 0x141, 
    0x143, 0x5, 0x18, 0xd, 0x2, 0x142, 0x141, 0x3, 0x2, 0x2, 0x2, 0x142, 
    0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x148, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x145, 0x7, 0x19, 0x2, 0x2, 0x145, 0x147, 0x5, 0x18, 0xd, 0x2, 0x146, 
    0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x148, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 
    0x14b, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 0x14b, 
    0x14c, 0x7, 0x18, 0x2, 0x2, 0x14c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x14d, 
    0x14f, 0x5, 0x20, 0x11, 0x2, 0x14e, 0x150, 0x5, 0x24, 0x13, 0x2, 0x14f, 
    0x14e, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0x13, 0x2, 0x2, 0x152, 
    0x157, 0x5, 0x22, 0x12, 0x2, 0x153, 0x154, 0x7, 0x19, 0x2, 0x2, 0x154, 
    0x156, 0x5, 0x22, 0x12, 0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x156, 
    0x159, 0x3, 0x2, 0x2, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x157, 
    0x158, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x159, 
    0x157, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15b, 0x7, 0x14, 0x2, 0x2, 0x15b, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0x26, 0x14, 0x2, 0x15d, 
    0x15e, 0x7, 0xc, 0x2, 0x2, 0x15e, 0x15f, 0x5, 0x26, 0x14, 0x2, 0x15f, 
    0x160, 0x8, 0x12, 0x1, 0x2, 0x160, 0x23, 0x3, 0x2, 0x2, 0x2, 0x161, 
    0x162, 0x7, 0xe, 0x2, 0x2, 0x162, 0x163, 0x7, 0x13, 0x2, 0x2, 0x163, 
    0x168, 0x5, 0x26, 0x14, 0x2, 0x164, 0x165, 0x7, 0x19, 0x2, 0x2, 0x165, 
    0x167, 0x5, 0x26, 0x14, 0x2, 0x166, 0x164, 0x3, 0x2, 0x2, 0x2, 0x167, 
    0x16a, 0x3, 0x2, 0x2, 0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 
    0x169, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16a, 
    0x168, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16c, 0x7, 0x14, 0x2, 0x2, 0x16c, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x7, 0x1c, 0x2, 0x2, 0x16e, 
    0x177, 0x8, 0x14, 0x1, 0x2, 0x16f, 0x170, 0x7, 0x1e, 0x2, 0x2, 0x170, 
    0x177, 0x8, 0x14, 0x1, 0x2, 0x171, 0x172, 0x7, 0x11, 0x2, 0x2, 0x172, 
    0x173, 0x7, 0x1e, 0x2, 0x2, 0x173, 0x174, 0x7, 0x12, 0x2, 0x2, 0x174, 
    0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x177, 0x8, 0x14, 0x1, 0x2, 0x176, 
    0x16d, 0x3, 0x2, 0x2, 0x2, 0x176, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x176, 
    0x171, 0x3, 0x2, 0x2, 0x2, 0x177, 0x27, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 
    0x7, 0x4, 0x2, 0x2, 0x179, 0x189, 0x8, 0x15, 0x1, 0x2, 0x17a, 0x17b, 
    0x7, 0x5, 0x2, 0x2, 0x17b, 0x189, 0x8, 0x15, 0x1, 0x2, 0x17c, 0x17d, 
    0x7, 0x6, 0x2, 0x2, 0x17d, 0x189, 0x8, 0x15, 0x1, 0x2, 0x17e, 0x17f, 
    0x7, 0x7, 0x2, 0x2, 0x17f, 0x189, 0x8, 0x15, 0x1, 0x2, 0x180, 0x181, 
    0x7, 0x8, 0x2, 0x2, 0x181, 0x189, 0x8, 0x15, 0x1, 0x2, 0x182, 0x183, 
    0x7, 0x9, 0x2, 0x2, 0x183, 0x189, 0x8, 0x15, 0x1, 0x2, 0x184, 0x185, 
    0x7, 0xa, 0x2, 0x2, 0x185, 0x189, 0x8, 0x15, 0x1, 0x2, 0x186, 0x187, 
    0x7, 0xb, 0x2, 0x2, 0x187, 0x189, 0x8, 0x15, 0x1, 0x2, 0x188, 0x178, 
    0x3, 0x2, 0x2, 0x2, 0x188, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x188, 0x17c, 
    0x3, 0x2, 0x2, 0x2, 0x188, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x188, 0x180, 
    0x3, 0x2, 0x2, 0x2, 0x188, 0x182, 0x3, 0x2, 0x2, 0x2, 0x188, 0x184, 
    0x3, 0x2, 0x2, 0x2, 0x188, 0x186, 0x3, 0x2, 0x2, 0x2, 0x189, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x2d, 0x33, 0x41, 0x48, 0x5a, 0x62, 0x69, 0x71, 
    0x73, 0x7b, 0x7f, 0x8a, 0x92, 0x98, 0xa2, 0xa7, 0xac, 0xae, 0xbd, 0xc3, 
    0xce, 0xd3, 0xd7, 0xe2, 0xe7, 0xeb, 0xf0, 0xf6, 0xfb, 0x101, 0x109, 
    0x10f, 0x116, 0x11c, 0x120, 0x126, 0x12d, 0x133, 0x139, 0x142, 0x148, 
    0x14f, 0x157, 0x168, 0x176, 0x188, 
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
