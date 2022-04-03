#include "ProceduresStore.hpp"
#include "sc-memory/utils/sc_log.hpp"


ProceduresStore::ProceduresStore()
{
  std::unordered_set<std::string> objects;
}

bool ProceduresStore::declareProcedure(std::string const & name)
{
  if (isProcedureDeclared(name))
    return false;

  //SC_LOG_DEBUG("Declare " + name + " procedure")
  procDeclarations.emplace_back(name);
  return true;
}

bool ProceduresStore::defineProcedure(scqParser::ProcDefinitionContext * ctx)
{
  std::string const procName = ctx->NAME()->getText();
  if (!isProcedureDeclared(procName))
    return false;

  //SC_LOG_ERROR("The procedure  " + procName + " is declared twice")
  procedures.insert({procName, {ctx->procParams(), ctx->block()}});
  return true;
}

bool ProceduresStore::isProcedureDeclared(std::string const & name)
{
  return std::find(procDeclarations.begin(), procDeclarations.end(), name) != procDeclarations.end();
}
