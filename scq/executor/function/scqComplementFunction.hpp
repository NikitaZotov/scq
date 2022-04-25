#pragma once

#include "scqFunction.hpp"


class scqComplementFunction : public scqFunction
{
public:
  ScAddr call(ScMemoryContext * context, ScAddrVector const & params) override;

private:
  ScAddr complementSets(
        ScMemoryContext * context,
        const ScAddr & firstSet,
        const ScAddr & secondSet,
        const ScType & resultType = ScType::NodeConst);
};
