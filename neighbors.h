#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions NeighborOffsets();
  Positions Neighbors(Position position);
  Positions Neighbors(Board board, Position position);
}
