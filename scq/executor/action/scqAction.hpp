#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_memory.hpp"


using ObjectsDefinitions = std::vector<std::array<std::string, 4>>;
using FunctionContext = std::unordered_map<std::string, ScAddr>;
using Objects = std::unordered_map<std::string, FunctionContext>;
using ObjectsTypes = std::unordered_map<std::string, std::string>;
using ProcedureDefinitions
      = std::unordered_map<
          std::string,
          std::pair<
              std::vector<std::pair<std::string, std::string>> *,
              std::pair<ObjectsDefinitions *, ObjectsTypes *>
          >
      >;

class scqAction
{
public:
  virtual ScAddr apply(
        ScMemoryContext * context,
        ScAddrVector const & params,
        ProcedureDefinitions * procDefs,
        ObjectsTypes * types,
        ObjectsDefinitions * definitions,
        FunctionContext * functionContext) = 0;

  std::string name;
  size_t index;
};
