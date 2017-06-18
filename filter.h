#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions withinBounds(Positions positions, Board board);
  Positions withMine(Positions positions, Board board);
  Positions coveredCells(Positions positions, Board board);
  Positions safeCells(Positions positions, Board board);
}