#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions allPositions(Board board);
  Positions minePositions(Board board);
  Positions flaggedPositions(Board board);
}