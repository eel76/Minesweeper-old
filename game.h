#pragma once
#include "board.h"

namespace minesweeper {
  bool gameUndecided(Board board);
  bool gameLost(Board board);
  bool gameWon(Board board);
}
