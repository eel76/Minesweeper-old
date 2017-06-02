#pragma once
#include "board.h"
#include "mine.h"

namespace minesweeper
{
  Board LayMines(Board board, MineCount mineCount);
  Board UncoverAllMines(Board board);
  bool AnyMineUncovered(Board const& board);
  bool AllSafeUncovered(Board const& board);
}
