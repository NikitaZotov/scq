#include "scqCallAction.hpp"
#include "../scqExecutor.hpp"
#include "../scqActionMap.hpp"
#include "../scqFunctionMap.hpp"


ScAddr scqCallAction::apply(
      ScMemoryContext * context,
      ScAddrVector const & params,
      ProcedureDefinitions * procDefs,
      ObjectsTypes * types,
      ObjectsDefinitions * definitions,
      FunctionContext * functionContext)
{
  auto const it = procDefs->find(name);

  if (it != procDefs->end())
  {
    auto * executor = new scqExecutor
          {
                procDefs,
                it->second.second.second,
                it->second.second.first
          };

    auto paramsDef = it->second.first;
    std::unordered_map<std::string, ScAddr> funcObjects;
    for (size_t i = 0; i < paramsDef->size(); ++i)
      funcObjects.insert({ paramsDef->at(i).first, params.at(i + 1) });

    executor->objects->insert({ name, funcObjects });
    executor->execute(scqActionMap().actions, name);

    auto const & calledIt = executor->objects->find(name);
    auto const & returnIt = calledIt->second.find("return");
    if (returnIt != calledIt->second.end())
    {
      if (functionContext->find(name) == functionContext->end())
        functionContext->insert({ name, returnIt->second });
      else
        functionContext->at(name) = returnIt->second;
    }

    delete executor;
  }
  else
  {
    if (name == "return")
    {
      functionContext->insert({ "return", params.at(1) });
      return params.at(1);
    }

    auto * function = scqFunctionMap().functions.find(name)->second;
    ScAddr result = function->call(context, params);

    if (functionContext->find(name) == functionContext->end())
      functionContext->insert({ name, result });
    else
      functionContext->at(name) = result;
  }

  context->EraseElement(params.at(0));

  return {};
}
