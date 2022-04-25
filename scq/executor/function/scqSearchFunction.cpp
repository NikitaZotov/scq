#include "scqSearchFunction.hpp"


ScAddr scqSearchFunction::call(ScMemoryContext * context, ScAddrVector const & params)
{
  std::cout << "Idtf: " << context->HelperGetSystemIdtf(params.at(1)) << std::endl;

  return {};
}
