#include "game.h"
#include "preparation.h"

using namespace minesweeper;

int main()
{
  auto board = prepareBoard(Dimensions{ columns(10), rows(10) }, 10_mines);

  while (!gameLost(board) && !gameWon(board))
    board = gameRound(board);

  evaluateGame(board);
  return 0;
}