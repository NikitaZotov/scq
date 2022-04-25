#pragma once

#include "scqAction.hpp"


class scqIfCallAction : public scqAction
{
public:
  ScAddr apply(
        ScMemoryContext * context,
        ScAddrVector const & params,
        ProcedureDefinitions * procDefs,
        ObjectsTypes * types,
        ObjectsDefinitions * definitions,
        FunctionContext * functionContext) override;
};
