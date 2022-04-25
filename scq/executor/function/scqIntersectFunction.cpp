#include "scqIntersectFunction.hpp"


ScAddr scqIntersectFunction::call(ScMemoryContext * context, ScAddrVector const & params)
{
  ScAddr intersectionAddr = intersectSets(context, { params.at(1), params.at(2) });

  ScAddr tuple = context->CreateNode(ScType::NodeConstTuple);
  ScAddr edge = context->CreateEdge(ScType::EdgeUCommonConst, params.at(1), params.at(2));
  edge = context->CreateEdge(ScType::EdgeDCommonConst, intersectionAddr, edge);

  ScAddr nrel_sets_intersection = context->HelperResolveSystemIdtf("nrel_sets_intersection");
  context->CreateEdge(ScType::EdgeAccessConstPosPerm, nrel_sets_intersection, edge);

  return intersectionAddr;
}

ScAddr scqIntersectFunction::intersectSets(
      ScMemoryContext * context,
      ScAddrVector const & sets,
      ScType const & resultType)
{
  ScAddr resultSet = context->CreateNode(resultType);

  for (const auto & set : sets)
  {
    ScIterator3Ptr firstIter3 = context->Iterator3(set, ScType::EdgeAccessConstPosPerm, ScType::Unknown);
    while (firstIter3->Next())
    {
      ScAddr element = firstIter3->Get(2);

      bool isCommon = true;

      if (!context->HelperCheckEdge(resultSet, element, ScType::EdgeAccessConstPosPerm))
      {
        for (const auto & otherSet : sets)
        {
          if (otherSet == set)
          {
            continue;
          }

          if (context->HelperCheckEdge(otherSet, element, ScType::EdgeAccessConstPosPerm))
          {
            isCommon = false;
            break;
          }
        }

        if (isCommon)
        {
          context->CreateEdge(ScType::EdgeAccessConstPosPerm, resultSet, element);
        }
      }
    }
  }

  return resultSet;
}
