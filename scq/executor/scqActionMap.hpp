#pragma once

#include "action/scqAction.hpp"
#include "action/scqAssignAction.hpp"
#include "action/scqCallAction.hpp"
#include "action/scqIfCallAction.hpp"

class scqActionMap
{
public:
  std::unordered_map<std::string, scqAction *> actions =
        {
              { "assign", new scqAssignAction() },
              { "call", new scqCallAction() },
              { "call_if", new scqIfCallAction() },
        };
};
