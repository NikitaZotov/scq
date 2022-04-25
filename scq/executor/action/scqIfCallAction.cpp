#include "scqIfCallAction.hpp"


ScAddr scqIfCallAction::apply(
      ScMemoryContext * context,
      ScAddrVector const & params,
      ProcedureDefinitions * procDefs,
      ObjectsTypes * types,
      ObjectsDefinitions * definitions,
      FunctionContext * functionContext)
{
  std::unordered_set<std::string> aliases;
  auto const & formTemplateItem = [context, &aliases](ScAddr const & addr) -> ScTemplateItemValue
  {
    if (context->GetElementType(addr).IsConst())
      return addr;
    else
    {
      std::string alias = context->HelperGetSystemIdtf(addr);
      auto const & it = aliases.find(alias);

      if (it == aliases.end())
      {
        aliases.insert(alias);
        return ScType::NodeVar >> alias;
      }
      else
        return alias;
    }
  };

  ScTemplate scTemplate;
  for (size_t i = 0; i < params.size(); i += 2)
  {
    ScAddr source = params[i];
    ScAddr target = params[i + 1];

    scTemplate.Triple(formTemplateItem(source), ScType::EdgeAccessVarPosPerm, formTemplateItem(target));
  }

  ScTemplateSearchResult result;
  context->HelperSearchTemplate(scTemplate, result);

  if (result.IsEmpty())
  {
    for (size_t i = index + params.size(); i < definitions->size(); ++i)
    {
      if (definitions->at(i)[0] == "end" || definitions->at(i)[1] == "search")
      {
        index = i;
        break;
      }
    }
  }
  else
  {
    for (auto const & alias : aliases)
    {
      functionContext->insert({ alias, result[0][alias] });
    }
  }

  return {};
}
