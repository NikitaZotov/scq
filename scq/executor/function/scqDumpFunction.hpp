#pragma once

#include "scqFunction.hpp"


class scqDumpFunction : public scqFunction
{
public:
  ScAddr call(ScMemoryContext * context, ScAddrVector const & params) override;
};
