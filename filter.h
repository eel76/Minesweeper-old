#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions withinBounds(Positions positions, Board board);
  Positions withMine(Positions positions, Board board);
  Positions coveredCells(Positions positions, Board board);
  Positions uncoveredCells(Positions positions, Board board);
  Positions markedCells(Positions positions, Board board);
  Positions unmarkedCells(Positions positions, Board board);
  Positions safeAreas(Positions positions, Board board);
}