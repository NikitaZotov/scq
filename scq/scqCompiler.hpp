#pragma once

#include "sc-memory/sc_memory.hpp"


class scqCompiler
{
public:
  sc_bool compile(sc_memory_params const & params);

private:
  ScMemoryContext * compilerCtx;
};
