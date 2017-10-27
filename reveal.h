#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper {
  Board mark(Board board, Positions positions);
  Board reveal(Board board, Positions positions);
} // namespace minesweeper
