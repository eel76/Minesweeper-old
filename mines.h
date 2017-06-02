#pragma once
#include "board.h"

namespace minesweeper
{
  Board UncoverAllMines(Board board);
  bool AnyMineUncovered(Board board);
  bool AllSafeUncovered(Board board);
}
