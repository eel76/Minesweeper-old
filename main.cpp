#include "game.h"
#include "preparation.h"

using namespace minesweeper;

int main()
{
  auto board = makeBoard(Dimensions{ columns(10), rows(10) }, 10);

  while (!gameLost(board) && !gameWon(board))
    board = gameRound(board);

  evaluateGame(board);
  return 0;
}