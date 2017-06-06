#pragma once
#include "board.h"

namespace minesweeper
{
  Board uncoverMines(Board board);
  bool anyMineUncovered(Board board);
  bool allSafeUncovered(Board board);
}
