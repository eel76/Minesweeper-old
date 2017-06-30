#include "player.h"
#include "ask.h"
#include "parse.h"
#include "print.h"

using namespace minesweeper;
using namespace std;

Player minesweeper::humanPlayer()
{
  return
  [](auto) { return parseMove(ask("Your move ([m|mark] row column): "s)); };
}

Player minesweeper::computerPlayer()
{
  return [](auto board) { return computerMove(board); };
}