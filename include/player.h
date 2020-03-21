#pragma once
#include "move.h"
#include <functional>

namespace minesweeper {
  using Player = std::function<Move(Board)>;
  inline auto requestMove(Player player, Board board) -> Move {
    return player(board);
  }
}
