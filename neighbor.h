#pragma once
#include "positions.h"

namespace minesweeper
{
  Positions neighborOffsets();
  Positions validNeighbors(Board board, Position position);
  Positions allNeighbors(Position position);
}
