#pragma once

#include "function/scqSetSystemIdtfFunction.hpp"
#include "function/scqResolveIdtfFunction.hpp"
#include "function/scqDumpFunction.hpp"
#include "function/scqRemoveFunction.hpp"
#include "function/scqUniteFunction.hpp"
#include "function/scqIntersectFunction.hpp"
#include "function/scqComplementFunction.hpp"


class scqFunctionMap
{
public:
  std::unordered_map<std::string, scqFunction *> functions =
        {
              { "set_idtf", new scqSetSystemIdtfFunction() },
              { "resolve_idtf", new scqResolveIdtfFunction() },
              { "dump", new scqDumpFunction() },
              { "remove", new scqRemoveFunction() },
              { "unite", new scqUniteFunction() },
              { "intersect", new scqIntersectFunction() },
              { "complement", new scqComplementFunction() },
        };
};
