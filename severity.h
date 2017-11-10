#pragma once
#include "hazard.h"

namespace minesweeper {
  struct Severity
  {
    int m_level;
  };
  bool     isDeadly(Severity severity);
  bool     isNegligible(Severity severity);
  Severity considered(Severity severity, Hazard hazard);
}
