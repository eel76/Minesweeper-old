#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions withinBounds(Positions positions, Board board);
  Positions coveredCells(Positions positions, Board board);
  Positions clearCells(Positions positions, Board board);
}