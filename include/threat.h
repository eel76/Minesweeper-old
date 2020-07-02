#pragma once
#include "severity.h"
#include "state.h"

#include <utility>

namespace minesweeper {
  struct Threat
  {
    State state;
    Mines mines;
  };
  auto   state(Threat threat) -> State;
  auto   mines(Threat threat) -> Mines;
  Threat toggleMark(Threat threat);
  Threat reveal(Threat threat);
  Threat mined(Threat threat, Hazard hazard);
  bool   isRevealed(Threat threat);
  bool   isDeadly(Threat threat);
  bool   isNegligible(Threat threat);
}
