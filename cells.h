#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Positions allPositions(Board board);
  Positions allMines(Board board);
}