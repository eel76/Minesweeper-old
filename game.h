#pragma once
#include "board.h"

namespace minesweeper
{
  bool gameLost(Board board);
  bool gameWon(Board board);
  Board gameRound(Board board);
  void evaluateGame(Board board);
}