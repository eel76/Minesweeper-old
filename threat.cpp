#include "threat.h"

auto minesweeper::marked(Threat threat) -> Threat {
  return Threat{ marked(std::get<State>(threat)), std::get<Mines>(threat) };
}

auto minesweeper::revealed(Threat threat) -> Threat {
  return Threat{ revealed(std::get<State>(threat)), std::get<Mines>(threat) };
}

auto minesweeper::mined(Threat threat, Hazard hazard) -> Threat {
  return Threat{ std::get<State>(threat), mined(std::get<Mines>(threat), hazard) };
}

auto minesweeper::isRevealed(Threat threat) -> bool {
  return isRevealed(std::get<State>(threat));
}

auto minesweeper::isMarked(Threat threat) -> bool {
  return isMarked(std::get<State>(threat));
}

auto minesweeper::isDeadly(Threat threat) -> bool {
  return isDeadly(std::get<Mines>(threat));
}

auto minesweeper::isNegligible(Threat threat) -> bool {
  return isNegligible(std::get<Mines>(threat));
}
