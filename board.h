#pragma once
#include "cell.h"
#include <map>

namespace minesweeper {
  using Board = std::map<Cell::first_type, Cell::second_type>;
  bool isLost(Board board);
  bool isWon(Board board);
}
