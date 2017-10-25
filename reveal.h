#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper {
  Board changeMark(Board board, Positions positions);
  Board reveal(Board board, Positions positions);
} // namespace minesweeper
