#include "scqAssignAction.hpp"


ScAddr scqAssignAction::apply(
      ScMemoryContext * context,
      ScAddrVector const & params,
      ProcedureDefinitions * procDefs,
      ObjectsTypes * types,
      ObjectsDefinitions * definitions,
      FunctionContext * functionContext)
{
  auto const & it = types->find(name);

  if (it != types->end())
  {
    auto const & varIt = functionContext->find(name);
    if (functionContext->find(name) == functionContext->end())
      functionContext->insert({ name, params.at(0) });
    else
      functionContext->at(name) = params.at(0);
  }

  return params.at(0);
}
