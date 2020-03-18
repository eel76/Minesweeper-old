#include "threat.h"

auto minesweeper::state(Threat threat) -> State {
  return threat.state;
}

auto minesweeper::mines(Threat threat) -> Mines {
  return threat.mines;
}

auto minesweeper::toggleMark(Threat threat) -> Threat {
  return { marked(state(threat)), mines(threat) };
}

auto minesweeper::reveal(Threat threat) -> Threat {
  return { revealed(state(threat)), mines(threat) };
}

auto minesweeper::mined(Threat threat, Hazard hazard) -> Threat {
  return { state(threat), mined(mines(threat), hazard) };
}

auto minesweeper::isRevealed(Threat threat) -> bool {
  return isRevealed(state(threat));
}

auto minesweeper::isMarked(Threat threat) -> bool {
  return isMarked(state(threat));
}

auto minesweeper::isDeadly(Threat threat) -> bool {
  return isDeadly(mines(threat));
}

auto minesweeper::isNegligible(Threat threat) -> bool {
  return isNegligible(mines(threat));
}
