#pragma once

#include "scqFunction.hpp"


class scqResolveIdtfFunction : public scqFunction
{
public:
  ScAddr call(ScMemoryContext * context, ScAddrVector const & params) override;
};
