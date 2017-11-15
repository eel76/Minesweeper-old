#include "game.h"
#include "cells.h"
#include "deadly.h"
#include "move.h"
#include "print.h"
#include "reveal.h"
#include <algorithm>

using namespace std::string_literals;

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

auto minesweeper::roundPlayed(Board board, Player player) -> Board {
  print(board);
  printCountdown(board);

  auto move = player(board);
  return move(board);
}

namespace minesweeper { namespace {

  void printIf(std::string const& text, bool condition) {
    print(std::map<bool, std::string>{ { true, text } }[condition]);
  }
}}

void minesweeper::evaluateGame(Board board) {
  print(revealed(board, cells(board) | isDeadly()));
  printIf("Game lost :-(\n"s, gameLost(board));
  printIf("Game won :-)\n"s, gameWon(board));
}
