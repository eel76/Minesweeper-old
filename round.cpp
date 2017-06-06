#include "round.h"
#include "mines.h"
#include "player.h"
#include "print.h"
#include "uncover.h"

using namespace minesweeper;

bool minesweeper::RoundPossible(Board board)
{
  return !AnyMineUncovered(board) && !AllSafeUncovered(board);
}

Board minesweeper::PlayRound(Board board)
{
  Print(board);
  Print("Your move (row, column): ");

  return Uncover(board, RequestPlayerMove());
}

void minesweeper::EvaluationRound(Board board)
{
  Print(UncoverMines(board));

  if (AnyMineUncovered(board))
    return Print("You loose :-(\n");

  if (AllSafeUncovered(board))
    return Print("You win :-)\n");
}
