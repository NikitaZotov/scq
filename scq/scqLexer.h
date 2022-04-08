
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


// Generated from /home/nikita/CLionProjects/ostis-web-platform/sc-machine/scq/scq/scq.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  scqLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, EDGE_OP = 9, ASSIGN_OP = 10, AS_OP = 11, IF_OP = 12, ELSE_OP = 13, 
    LEFT_TRIANGLE_BRACKET = 14, RIGHT_TRIANGLE_BRACKET = 15, LEFT_SQUARE_BRACKET = 16, 
    RIGHT_SQUARE_BRACKET = 17, LEFT_FIGURE_BRACKET = 18, RIGHT_FIGURE_BRACKET = 19, 
    LEFT_CURL_BRACKET = 20, RIGHT_CURL_BRACKET = 21, COMMA = 22, SEMICOLON = 23, 
    PROCEDURE_TYPE = 24, OBJECT_TYPE = 25, STRING = 26, NAME = 27, LETTER = 28, 
    DIGIT = 29, WS = 30, SL_COMMENT = 31
  };

  explicit scqLexer(antlr4::CharStream *input);
  ~scqLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

