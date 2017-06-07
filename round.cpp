#include "round.h"
#include "evaluation.h"
#include "player.h"
#include "print.h"
#include "uncover.h"

using namespace minesweeper;

Board minesweeper::playRound(Board board)
{
  print(board);
  print("Your move (row, column): ");

  return uncoverCell(board, playerMove());
}

bool minesweeper::roundPossible(Board board)
{
  return !gameLost(board) && !gameWon(board);
}

void minesweeper::evaluationRound(Board board)
{
  print(uncoverMines(board));

  if (gameLost(board))
    return print("You loose :-(\n");

  if (gameWon(board))
    return print("You win :-)\n");
}
