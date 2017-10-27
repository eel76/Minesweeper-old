#include "threat.h"

minesweeper::Threat minesweeper::markAction(Threat threat) {
  return Threat{ mark(std::get<State>(threat)), std::get<Severity>(threat) };
}

minesweeper::Threat minesweeper::revealAction(Threat threat) {
  return Threat{ reveal(std::get<State>(threat)), std::get<Severity>(threat) };
}

minesweeper::Threat minesweeper::consider(Threat threat, Hazard hazard) {
  return Threat{ std::get<State>(threat), consider(std::get<Severity>(threat), hazard) };
}

bool minesweeper::isRevealed(Threat threat) {
  return std::get<State>(threat) == State::Revealed;
}

bool minesweeper::isRecognized(Threat threat) {
  return std::get<State>(threat) == State::Marked;
}

bool minesweeper::deadly(Threat threat) {
  return deadly(std::get<Severity>(threat));
}
