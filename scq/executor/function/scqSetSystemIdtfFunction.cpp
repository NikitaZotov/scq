#include "scqSetSystemIdtfFunction.hpp"


ScAddr scqSetSystemIdtfFunction::call(ScMemoryContext * context, ScAddrVector const & params)
{
  ScAddr nrelSystemIdtf = context->HelperResolveSystemIdtf("nrel_system_identifier");

  ScTemplate templ;
  templ.TripleWithRelation(
        ScType::Unknown,
        ScType::EdgeDCommonVar,
        params.at(2),
        ScType::EdgeAccessVarPosPerm,
        nrelSystemIdtf
  );
  ScTemplateSearchResult result;
  context->HelperSearchTemplate(templ, result);

  if (result.Size() == 0)
  {
    ScAddr edge = context->CreateEdge(ScType::EdgeDCommonConst, params.at(1), params.at(2));
    context->CreateEdge(ScType::EdgeAccessConstPosPerm, nrelSystemIdtf, edge);
  }

  return params.at(2);
}
