#include "player.h"
#include "ask.h"
#include "computer.h"
#include "parse.h"
#include "game.h"

using namespace minesweeper;
using namespace std;

Player human()
{
  return
  [](auto) { return parseMove(ask("Your move: [(m)ark] <row> <column>: "s)); };
}

Player computer()
{
  return [](auto board) { return computerMove(board); };
}

Player minesweeper::choosePlayer()
{
  auto players = map<string, Player>{ { "h"s, human() }, { "c"s, computer() } };
  auto player  = Player{};

  while (!player)
    player = players[ask("Player: (h)uman or (c)omputer? "s)];

  return player;
}

void minesweeper::play(Player player, Board board)
{
  while (gameUndecided(board))
    board = playRound(board, player);

  evaluateGame(board);
}