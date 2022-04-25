#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_memory.hpp"


class scqFunction
{
public:
  virtual ScAddr call(ScMemoryContext * context, ScAddrVector const & params) = 0;
};
