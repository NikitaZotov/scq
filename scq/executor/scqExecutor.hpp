#pragma once

#include "sc-memory/sc_memory.hpp"
#include "action/scqAction.hpp"


class scqExecutor
{
public:
  scqExecutor(ProcedureDefinitions * procDefs, ObjectsTypes * types, ObjectsDefinitions * definitions);

  sc_bool execute(std::unordered_map<std::string, scqAction *> actions, std::string const & function = "");

  ~scqExecutor();

  Objects * objects;

private:
  ProcedureDefinitions * procDefs;
  ObjectsTypes * types;
  ObjectsDefinitions * definitions;
  ScMemoryContext * context;

  std::unordered_map<std::string, ScAddr> setTypes;

  ScAddr resolveParam(std::string const & objName, FunctionContext & context);

  ScAddr createObject(std::string const & objName, FunctionContext & functionCtx);
};
