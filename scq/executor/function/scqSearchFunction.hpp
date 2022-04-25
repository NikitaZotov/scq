#pragma once

#include "scqFunction.hpp"


class scqSearchFunction : public scqFunction
{
public:
  ScAddr call(ScMemoryContext * context, ScAddrVector const & params) override;
};
