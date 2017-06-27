#include "player.h"
#include "input.h"
#include "parse.h"
#include "print.h"

using namespace minesweeper;
using namespace std;

Player minesweeper::humanPlayer()
{
  return [](auto) {
    print("Your move ([m|mark] row column): "s);
    return parseMove(inputLine());
  };
}

Player minesweeper::computerPlayer()
{
  return [](auto board) { return computerMove(board); };
}