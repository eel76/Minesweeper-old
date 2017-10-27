#pragma once
#include "hazard.h"
#include <string>

namespace minesweeper {
  struct Severity
  {
    int m_level;
  };
  inline bool deadly(Severity severity) {
    return severity.m_level >= 9;
  }
  inline bool isNegligible(Severity severity) {
    return severity.m_level == 0;
  }
  Severity consider(Severity severity, Hazard hazard);
}
