#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions neighborOffsets();
  Positions neighborPositions(Position position);
  Positions neighborPositions(Board board, Position position);
}
