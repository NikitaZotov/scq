#include "scqRemoveFunction.hpp"


ScAddr scqRemoveFunction::call(ScMemoryContext * context, ScAddrVector const & params)
{
  context->EraseElement(params.at(1));

  return {};
}
