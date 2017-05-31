#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions NeighborOffsets();
  Positions Neighbors(Position const& position);
  Positions Neighbors(Board const& board, Position const& position);
}
