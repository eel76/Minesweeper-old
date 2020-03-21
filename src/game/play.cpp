#include "game/play.h"

#include "ask.h"
#include "cells.h"
#include "deadly.h"
#include "group.h"
#include "marked.h"
#include "reveal.h"
#include "to_string.h"

using namespace std::string_literals;

namespace minesweeper::game { namespace {

  void print(Board board) {
    for (auto&& [row, cells] : byRow(cellsOf(board)))
      minesweeper::print(to_string(cells) + "\n"s);
  }

  void printCountdown(Board board) {
    auto countdown = size(cellsOf(board) | isDeadly()) - size(cellsOf(board) | marked());
    minesweeper::print("Mines left: "s + std::to_string(countdown) + "\n"s);
  }

  auto perform(Move move, Board board) -> Board {
    return move(board);
  }

  auto doMove(Player player, Board board) -> Board {
    print(board);
    printCountdown(board);

    return perform(requestMove(player, board), board);
  }

  auto isPlayable(Board board) -> bool {
    return !isLost(board) && !isWon(board);
  }
}}

void minesweeper::game::play(Player player, Board board) {
  while (isPlayable(board))
    board = doMove(player, board);

  print(reveal(board, cellsOf(board) | isDeadly()));
  printIf("Game lost :-(\n"s, isLost(board));
  printIf("Game won :-)\n"s, isWon(board));
  askString("Press ENTER to quit...");
}
