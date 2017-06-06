#pragma once
#include "board.h"

namespace minesweeper
{
  Board UncoverMines(Board board);
  bool AnyMineUncovered(Board board);
  bool AllSafeUncovered(Board board);
}
