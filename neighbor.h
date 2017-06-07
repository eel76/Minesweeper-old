#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions neighborOffsets();
  Positions neighborPositions(Board board, Position position);
}
