#pragma once
#include "hazard.h"
#include <map>

namespace minesweeper {
  using Mines = std::map<Hazard, int>;

  inline Mines mined(Mines mines, Hazard hazard) {
    mines[hazard]++;
    return mines;
  }
  inline bool isDeadly(Mines mines) {
    return mines[Hazard::Deadly] != 0;
  }
  inline bool isNegligible(Mines mines) {
    return mines.empty();
  }
}
