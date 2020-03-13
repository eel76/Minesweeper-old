#pragma once
#include "position.h"
#include "threat.h"
#include <map>

namespace minesweeper {
  using Board = std::map<Position, Threat>;
  bool isLost(Board board);
  bool isWon(Board board);
}
