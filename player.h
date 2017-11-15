#pragma once
#include "move.h"
#include <functional>

namespace minesweeper {
  using Player = std::function<Move(Board)>;
  Player choosePlayer();
  void   play(Player player, Board board);
  Board  roundPlayed(Board board, Player player);
  void   evaluateGame(Board board);
}
