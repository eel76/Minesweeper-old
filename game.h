#pragma once
#include "board.h"
#include "player.h"

namespace minesweeper
{
  bool  gameLost(Board board);
  bool  gameWon(Board board);
  Board gameRound(Board board, Player player);
  void  evaluateGame(Board board);
}