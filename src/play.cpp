#include "play.h"

#include "ask.h"
#include "cells.h"
#include "deadly.h"
#include "reveal.h"

using namespace std::string_literals;

namespace minesweeper { namespace {

  auto playRound(Board board, Player player) {
    print(board);
    printCountdown(board);

    auto move = player(board);
    return move(board);
  }

  void printIf(std::string const& text, bool condition) {
    print(std::map<bool, std::string>{ { true, text } }[condition]);
  }
}}

void minesweeper::play(Board board, Player player) {
  while (!isLost(board) && !isWon(board))
    board = playRound(board, player);

  print(reveal(board, cellsOf(board) | isDeadly()));
  printIf("Game lost :-(\n"s, isLost(board));
  printIf("Game won :-)\n"s, isWon(board));
  askString("Press ENTER to quit...");
}
