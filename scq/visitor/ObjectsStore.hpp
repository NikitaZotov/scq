#pragma once


#include <vector>
#include <string>
#include "../scqParser.h"

class ObjectsStore
{
public:
  ObjectsStore();

  bool declareObject(antlr4::tree::TerminalNode * ctx);

  bool defineObject(antlr4::tree::TerminalNode * ctx);

private:
  std::vector<std::string> objectDeclarations;

  bool isObjectDeclared(std::string const & name);
};
