#pragma once

#include "scqFunction.hpp"


class scqIntersectFunction : public scqFunction
{
public:
  ScAddr call(ScMemoryContext * context, ScAddrVector const & params) override;

private:
  ScAddr intersectSets(
        ScMemoryContext * context,
        ScAddrVector const & sets,
        ScType const & resultType = ScType::NodeConst);
};
