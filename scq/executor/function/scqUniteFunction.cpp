#include "scqUniteFunction.hpp"


ScAddr scqUniteFunction::call(ScMemoryContext * context, ScAddrVector const & params)
{
  ScAddr unionAddr = uniteSets(context, { params.at(1), params.at(2) });

  ScAddr tuple = context->CreateNode(ScType::NodeConstTuple);
  ScAddr edge = context->CreateEdge(ScType::EdgeUCommonConst, params.at(1), params.at(2));
  edge = context->CreateEdge(ScType::EdgeDCommonConst, unionAddr, edge);

  ScAddr nrel_sets_union = context->HelperResolveSystemIdtf("nrel_sets_union");
  context->CreateEdge(ScType::EdgeAccessConstPosPerm, nrel_sets_union, edge);

  return unionAddr;
}

ScAddr scqUniteFunction::uniteSets(ScMemoryContext * context, ScAddrVector const & sets, ScType const & resultType)
{
  ScAddr resultSet = context->CreateNode(resultType);

  for (const auto & set : sets)
  {
    ScIterator3Ptr firstIter3 = context->Iterator3(set, ScType::EdgeAccessConstPosPerm, ScType::Unknown);

    while (firstIter3->Next())
    {
      ScAddr element = firstIter3->Get(2);

      if (!context->HelperCheckEdge(resultSet, element, ScType::EdgeAccessConstPosPerm))
      {
        context->CreateEdge(ScType::EdgeAccessConstPosPerm, resultSet, element);
      }
    }
  }

  return resultSet;
}