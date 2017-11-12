#include "player.h"
#include "ask.h"
#include "computer.h"
#include "game.h"
#include "human.h"

using namespace std::string_literals;

auto minesweeper::choosePlayer() -> Player {
  auto players = std::map<std::string, Player>{ { "h"s, humanPlayer() },
                                                { "c"s, computerPlayer() } };
  auto player  = Player{};

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
