#pragma once
#include "severity.h"
#include "state.h"
#include <utility>

namespace minesweeper {
  using Threat = std::pair<State, Severity>;
  Threat marked(Threat threat);
  Threat revealed(Threat threat);
  Threat mined(Threat threat, Hazard hazard);
  bool   isRevealed(Threat threat);
  bool   isMarked(Threat threat);
  bool   isDeadly(Threat threat);
  bool   isNegligible(Threat threat);
}
