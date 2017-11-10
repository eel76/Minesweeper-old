#pragma once
#include "severity.h"
#include "state.h"
#include <utility>

namespace minesweeper {
  using Threat = std::pair<State, Severity>;
  Threat markAction(Threat threat);
  Threat revealAction(Threat threat);
  Threat considered(Threat threat, Hazard hazard);
  bool   isRevealed(Threat threat);
  bool   isRecognized(Threat threat);
  bool   isDeadly(Threat threat);
}
