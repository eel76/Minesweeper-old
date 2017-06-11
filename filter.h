#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions withinBounds(Positions positions, Board board);
  Positions coveredCells(Positions positions, Board board);
  Positions withoutMines(Positions positions, Board board);
  Positions onlyMines(Board board, Positions positions);
  Positions onlyFirst(size_t count, Positions positions);
}
