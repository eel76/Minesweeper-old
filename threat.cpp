#include "threat.h"

auto minesweeper::marked(Threat threat) -> Threat {
  return Threat{ marked(std::get<State>(threat)), std::get<Severity>(threat) };
}

auto minesweeper::revealed(Threat threat) -> Threat {
  return Threat{ revealed(std::get<State>(threat)), std::get<Severity>(threat) };
}

auto minesweeper::mined(Threat threat, Position position) -> Threat {
  return Threat{ std::get<State>(threat), mined(std::get<Severity>(threat), position) };
}

auto minesweeper::isRevealed(Threat threat) -> bool {
  return isRevealed(std::get<State>(threat));
}

auto minesweeper::isMarked(Threat threat) -> bool {
  return isMarked(std::get<State>(threat));
}

auto minesweeper::isDeadly(Threat threat) -> bool {
  return isDeadly(std::get<Severity>(threat));
}
