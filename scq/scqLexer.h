
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


// Generated from scq.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace scq {


class  scqLexer : public antlr4::Lexer {
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

  scqLexer(antlr4::CharStream *input);
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

}  // namespace scq
