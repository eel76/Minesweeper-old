#include "round.h"
#include "mines.h"
#include "player.h"
#include "print.h"
#include "uncover.h"

using namespace minesweeper;

bool minesweeper::roundPossible(Board board)
{
  return !anyMineUncovered(board) && !allSafeUncovered(board);
}

Board minesweeper::playRound(Board board)
{
  print(board);
  print("Your move (row, column): ");

  return uncoverCell(board, playerMove());
}

void minesweeper::evaluationRound(Board board)
{
  print(uncoverMines(board));

  if (anyMineUncovered(board))
    return print("You loose :-(\n");

  if (allSafeUncovered(board))
    return print("You win :-)\n");
}
