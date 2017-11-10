#include "threat.h"

minesweeper::Threat minesweeper::markAction(Threat threat) {
  return Threat{ marked(std::get<State>(threat)), std::get<Severity>(threat) };
}

minesweeper::Threat minesweeper::revealAction(Threat threat) {
  return Threat{ revealed(std::get<State>(threat)), std::get<Severity>(threat) };
}

minesweeper::Threat minesweeper::considered(Threat threat, Hazard hazard) {
  return Threat{ std::get<State>(threat), considered(std::get<Severity>(threat), hazard) };
}

bool minesweeper::isRevealed(Threat threat) {
  return std::get<State>(threat) == State::Revealed;
}

bool minesweeper::isRecognized(Threat threat) {
  return std::get<State>(threat) == State::Marked;
}

bool minesweeper::isDeadly(Threat threat) {
  return isDeadly(std::get<Severity>(threat));
}
