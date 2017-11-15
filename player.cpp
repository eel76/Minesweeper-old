#include "player.h"
#include "ask.h"
#include "cells.h"
#include "computer.h"
#include "deadly.h"
#include "human.h"
#include "reveal.h"

using namespace std::string_literals;

namespace minesweeper { namespace {

  void printIf(std::string const& text, bool condition) {
    print(std::map<bool, std::string>{ { true, text } }[condition]);
  }
}}

auto minesweeper::choosePlayer() -> Player {
  auto players = std::map<std::string, Player>{ { "h"s, humanPlayer() },
                                                { "c"s, computerPlayer() } };
  auto player  = Player{};

  while (!player)
    player = players[askString("Player: (h)uman or (c)omputer? "s)];

  return player;
}

void minesweeper::play(Player player, Board board) {
  while (!isLost(board) && !isWon(board))
    board = roundPlayed(board, player);

  print(revealed(board, cells(board) | isDeadly()));
  printIf("Game lost :-(\n"s, isLost(board));
  printIf("Game won :-)\n"s, isWon(board));
  askString("Press ENTER to quit...");
}

auto minesweeper::roundPlayed(Board board, Player player) -> Board {
  print(board);
  printCountdown(board);

  auto move = player(board);
  return move(board);
}
