#include "scqComplementFunction.hpp"


ScAddr scqComplementFunction::call(ScMemoryContext * context, ScAddrVector const & params)
{
  ScAddr complementAddr = complementSets(context, params.at(1), params.at(2));

  ScAddr tuple = context->CreateNode(ScType::NodeConstTuple);
  ScAddr edge = context->CreateEdge(ScType::EdgeDCommonConst, params.at(1), params.at(2));
  edge = context->CreateEdge(ScType::EdgeDCommonConst, complementAddr, edge);

  ScAddr nrel_sets_complement = context->HelperResolveSystemIdtf("nrel_sets_complement");
  context->CreateEdge(ScType::EdgeAccessConstPosPerm, nrel_sets_complement, edge);

  return complementAddr;
}

ScAddr scqComplementFunction::complementSets(
      ScMemoryContext * context,
      ScAddr const & firstSet,
      ScAddr const & secondSet,
      ScType const & resultType)
{
  SC_CHECK_PARAM(firstSet, ("Invalid first set address"))
  SC_CHECK_PARAM(secondSet, ("Invalid second set address"))

  ScAddr resultSet = context->CreateNode(resultType);

  ScIterator3Ptr secondIter3 = context->Iterator3(secondSet, ScType::EdgeAccessConstPosPerm, ScType::Unknown);
  while (secondIter3->Next())
  {
    ScAddr element = secondIter3->Get(2);

    if (!context->HelperCheckEdge(firstSet, element, ScType::EdgeAccessConstPosPerm) &&
        !context->HelperCheckEdge(resultSet, element, ScType::EdgeAccessConstPosPerm))
    {
      context->CreateEdge(ScType::EdgeAccessConstPosPerm, resultSet, element);
    }
  }

  return resultSet;
}
