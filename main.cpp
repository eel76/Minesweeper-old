#include "preparation.h"
#include "game.h"

using namespace minesweeper;

int main()
{
  auto board = prepareBoard(Size{ columns(10), rows(10) }, 10_mines);

  while (!gameLost(board) && !gameWon(board))
    board = gameRound(board);

  evaluateGame(board);
  return 0;
}
