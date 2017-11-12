#pragma once
#include "hazard.h"

namespace minesweeper {
  struct Severity
  {
    int m_level;
  };
  Severity considered(Severity severity, Hazard hazard);
  bool     isDeadly(Severity severity);
  bool     isNegligible(Severity severity);
}
