#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions allCells(Board board);
  Positions onlyInside(Board board, Positions positions);
  Positions onlyMines(Board board, Positions positions);
  Positions onlyFirst(size_t count, Positions positions);
}
