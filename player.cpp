#include "player.h"
#include "ask.h"
#include "computer.h"
#include "game.h"
#include "parse.h"

using namespace minesweeper;
using namespace std;

Player human() {
  return [](auto) {
    return parseMove(askString("Your move: [(m)ark] <row> <column>: "s));
  };
}

Player minesweeper::choosePlayer() {
  auto players =
  map<std::string, Player>{ { "h"s, human() }, { "c"s, computerPlayer() } };
  auto player = Player{};

  while (!player)
    player = players[askString("Player: (h)uman or (c)omputer? "s)];

  return player;
}

void minesweeper::play(Player player, Board board) {
  while (gameUndecided(board))
    board = roundPlayed(board, player);

  evaluateGame(board);
  askString("Press ENTER to quit...");
}
