#include "game.h"
#include <algorithm>

auto minesweeper::gameUndecided(Board board) -> bool {
  return !gameLost(board) && !gameWon(board);
}

auto minesweeper::gameLost(Board board) -> bool {
  return any_of(begin(board), end(board), [](auto cell) {
    return isRevealed(std::get<Threat>(cell)) & isDeadly(std::get<Threat>(cell));
  });
}

auto minesweeper::gameWon(Board board) -> bool {
  // FIXME: (deadly => marked) and (!deadly => revealed)
  // (!deadly || marked) && (deadly || revealed)

  return all_of(begin(board), end(board), [](auto cell) {
    return isRevealed(std::get<Threat>(cell)) ^ isDeadly(std::get<Threat>(cell));
  });
}
