
#include "sc-memory/sc_memory.hpp"
#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_keynodes.hpp"


// Generated from /home/nikita/CLionProjects/ostis-web-platform/sc-machine/scq/scq/scq.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  scqLexer : public antlr4::Lexer {
public:
  enum {
    EDGE_OP = 1, ASSIGN_OP = 2, AS_OP = 3, IF_OP = 4, ELSE_OP = 5, LEFT_TRIANGLE_BRACKET = 6, 
    RIGHT_TRIANGLE_BRACKET = 7, LEFT_SQUARE_BRACKET = 8, RIGHT_SQUARE_BRACKET = 9, 
    LEFT_FIGURE_BRACKET = 10, RIGHT_FIGURE_BRACKET = 11, LEFT_CURL_BRACKET = 12, 
    RIGHT_CURL_BRACKET = 13, COMMA = 14, SEMICOLON = 15, SET_OPERATION = 16, 
    PROCEDURE_TYPE = 17, OBJECT_TYPE = 18, STRING = 19, NAME = 20, LETTER = 21, 
    DIGIT = 22, WS = 23, SL_COMMENT = 24
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

