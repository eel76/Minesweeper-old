#include "game.h"
#include "move.h"
#include "preparation.h"

using namespace minesweeper;
using namespace std;

void play(Player player, Board board)
{
  while (gameUndecided(board))
    board = playRound(board, player);

  evaluateGame(board);
}

#include <iostream>

int main()
{
  play(choosePlayer(), makeBoard(Dimensions{ 9_columns, 9_rows }, 10));
  std::cin.get();
  return 0;
}