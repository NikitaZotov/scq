#include "scqResolveIdtfFunction.hpp"


ScAddr scqResolveIdtfFunction::call(ScMemoryContext * context, ScAddrVector const & params)
{
  ScAddr nrelSystemIdtf = context->HelperResolveSystemIdtf("nrel_system_identifier");

  ScTemplate templ;
  templ.TripleWithRelation(
        ScType::Unknown,
        ScType::EdgeDCommonVar,
        params.at(1),
        ScType::EdgeAccessVarPosPerm,
        nrelSystemIdtf
  );
  ScTemplateSearchResult result;
  context->HelperSearchTemplate(templ, result);

  ScAddr addr;
  if (result.Size() == 0)
  {
    addr = context->CreateNode(ScType::NodeConst);
    ScAddr edge = context->CreateEdge(ScType::EdgeDCommonConst, addr, params.at(1));
    context->CreateEdge(ScType::EdgeAccessConstPosPerm, nrelSystemIdtf, edge);
  }
  else
  {
    addr = result[0][0];
  }

  return addr;
}
