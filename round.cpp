#include "round.h"
#include "evaluation.h"
#include "filter.h"
#include "player.h"
#include "print.h"
#include "uncover.h"

using namespace minesweeper;

Board minesweeper::playRound(Board board)
{
  print(board);
  print("Your move (row, column): ");

  return uncover(board, playerMove());
}

bool minesweeper::roundPossible(Board board)
{
  return !gameLost(board) && !gameWon(board);
}

void minesweeper::evaluationRound(Board board)
{
  print(uncover(board, onlyMines(board, allCells(board))));

  if (gameLost(board))
    return print("You loose :-(\n");

  if (gameWon(board))
    return print("You win :-)\n");
}
