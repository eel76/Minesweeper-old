#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper {
  Board layMine(Board board, Position position);
  Board layMines(Board board, Positions positions);
  Board layMines(Board board, unsigned count);
}
