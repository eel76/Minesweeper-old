#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions neighborOffsets();
  Positions cellNeighbors(Position position);
  Positions cellNeighbors(Board board, Position position);
}
