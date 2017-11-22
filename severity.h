#pragma once
#include "hazard.h"
#include <map>

namespace minesweeper {
  using Severity = std::map<Hazard, int>;

  inline Severity mined(Severity severity, Hazard hazard) {
    severity[hazard]++;
    return severity;
  }
  inline bool isDeadly(Severity severity) {
    return severity[Hazard::Mine] != 0;
  }
  inline bool isNegligible(Severity severity) {
    return severity.empty();
  }
}
