#pragma once

#include "scqFunction.hpp"


class scqSetSystemIdtfFunction : public scqFunction
{
public:
  ScAddr call(ScMemoryContext * context, ScAddrVector const & params) override;
};
