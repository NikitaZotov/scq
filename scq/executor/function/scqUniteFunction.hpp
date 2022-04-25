#pragma once

#include "scqFunction.hpp"


class scqUniteFunction : public scqFunction
{
public:
  ScAddr call(ScMemoryContext * context, ScAddrVector const & params) override;

private:
  ScAddr uniteSets(
        ScMemoryContext * context,
        ScAddrVector const & sets,
        ScType const & resultType = ScType::NodeConst);
};

