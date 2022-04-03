#pragma once


#include <vector>
#include <string>
#include "../scqParser.h"

class ProceduresStore
{
public:
  ProceduresStore();

  bool declareProcedure(std::string const & name);

  bool defineProcedure(scqParser::ProcDefinitionContext * ctx);

private:
  std::vector<std::string> procDeclarations;
  std::map<std::string, std::pair<scqParser::ProcParamsContext *, scqParser::BlockContext *>> procedures;

  bool isProcedureDeclared(std::string const & name);
};
