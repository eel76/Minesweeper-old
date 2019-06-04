#pragma once
#include "position.h"
#include "threat.h"

namespace minesweeper {
  using Cell = std::pair<Position, Threat>;
  bool isRevealed(Cell cell);
  bool isDeadly(Cell cell);
}
