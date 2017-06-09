#include "preparation.h"
#include "game.h"

using namespace minesweeper;

int main()
{
  auto board = prepareBoard({ 10_columns, 10_rows }, 10_mines);

  while (!gameLost(board) && !gameWon(board))
    board = gameRound(board);

  evaluateGame(board);
  return 0;
}
