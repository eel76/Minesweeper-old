#pragma once
#include "hazard.h"
#include <map>

namespace minesweeper {
  using Mines = std::map<Hazard, int>;

  inline Mines mined(Mines severity, Hazard hazard) {
    severity[hazard]++;
    return severity;
  }
  inline bool isDeadly(Mines severity) {
    return severity[Hazard::Deadly] != 0;
  }
  inline bool isNegligible(Mines severity) {
    return severity.empty();
  }
}
