#pragma once

#include "scqFunction.hpp"


class scqRemoveFunction : public scqFunction
{
public:
  ScAddr call(ScMemoryContext * context, ScAddrVector const & params) override;
};
