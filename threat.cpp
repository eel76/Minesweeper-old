#include "threat.h"

minesweeper::Threat minesweeper::marked(Threat threat) {
  return Threat{ marked(std::get<State>(threat)), std::get<Severity>(threat) };
}

minesweeper::Threat minesweeper::revealed(Threat threat) {
  return Threat{ revealed(std::get<State>(threat)), std::get<Severity>(threat) };
}

minesweeper::Threat minesweeper::considered(Threat threat, Hazard hazard) {
  return Threat{ std::get<State>(threat), considered(std::get<Severity>(threat), hazard) };
}

bool minesweeper::isRevealed(Threat threat) {
  return isRevealed(std::get<State>(threat));
}

bool minesweeper::isMarked(Threat threat) {
  return isMarked(std::get<State>(threat));
}

bool minesweeper::isDeadly(Threat threat) {
  return isDeadly(std::get<Severity>(threat));
}
