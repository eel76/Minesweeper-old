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
  play(choosePlayer(), makeBoard(Dimensions{ 40_columns, 20_rows }, 100));
  return 0;
}