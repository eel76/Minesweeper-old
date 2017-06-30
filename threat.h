#pragma once
#include "visibility.h"
#include "severity.h"
#include <utility>

namespace minesweeper
{
  using Threat = std::pair<Visibility, Severity>;
  Threat        changeGuess(Threat threat);
  Threat        reveal(Threat threat);
  Threat        consider(Threat threat, Hazard hazard);
  std::string toString(Threat threat);
  bool        isRevealed(Threat threat);
  bool        isRecognized(Threat threat);
  bool        isDeadly(Threat threat);
}