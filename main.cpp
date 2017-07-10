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

int main()
{
  play(choosePlayer(), makeBoard(Dimensions{ 10_columns, 10_rows }, 10));
  return 0;
}