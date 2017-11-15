#include "board.h"
#include <algorithm>

auto minesweeper::isLost(Board board) -> bool {
  return any_of(begin(board), end(board), [](auto cell) {
    return isRevealed(std::get<Threat>(cell)) & isDeadly(std::get<Threat>(cell));
  });
}

auto minesweeper::isWon(Board board) -> bool {
  // FIXME: (deadly => marked) and (!deadly => revealed)
  // (!deadly || marked) && (deadly || revealed)

  return all_of(begin(board), end(board), [](auto cell) {
    return isRevealed(std::get<Threat>(cell)) ^ isDeadly(std::get<Threat>(cell));
  });
}
