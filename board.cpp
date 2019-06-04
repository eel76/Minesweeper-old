#include "board.h"
#include <algorithm>

auto minesweeper::isLost(Board board) -> bool {
  return any_of(begin(board), end(board), [](auto cell) {
    return isRevealed(cell) & isDeadly(cell);
  });
}

auto minesweeper::isWon(Board board) -> bool {
  return all_of(begin(board), end(board), [](auto cell) {
    return isRevealed(cell) ^ isDeadly(cell);
  });
}
