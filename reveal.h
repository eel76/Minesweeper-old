#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper {
  Board markAction(Board board, Positions positions);
  Board revealAction(Board board, Positions positions);
} // namespace minesweeper
