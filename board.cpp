#include "board.h"
#include <algorithm>

auto minesweeper::isLost(Board board) -> bool {
  return any_of(begin(board), end(board), [](auto cell) {
    auto [position, threat] = cell; 
    return isRevealed(threat) & isDeadly(threat);
  });
}

auto minesweeper::isWon(Board board) -> bool {
  return all_of(begin(board), end(board), [](auto cell) {
    auto [position, threat] = cell;
    return isRevealed(threat) ^ isDeadly(threat);
  });
}
