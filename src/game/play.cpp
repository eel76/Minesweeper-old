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
      io::print(to_string(cells) + "\n"s);

    auto const countdown =
    size(cellsOf(board) | isDeadly()) - size(cellsOf(board) | marked());
    io::print("Mines left: "s + std::to_string(countdown) + "\n"s);
  }

  void printIf(std::string const& text, bool condition) {
    if (condition)
      io::print(text);
  }

  auto perform(Move move, Board board) -> Board {
    return move(board);
  }

  auto doMove(Player player, Board board) -> Board {
    print(board);

    return perform(requestMove(player, board), board);
  }
}}

void minesweeper::game::play(Player player, Board board) {
  while (!isLost(board) && !isWon(board))
    board = doMove(player, board);

  print(reveal(board, cellsOf(board) | isDeadly()));
  printIf("Game lost :-(\n"s, isLost(board));
  printIf("Game won :-)\n"s, isWon(board));
  askString("Press ENTER to quit...");
}
