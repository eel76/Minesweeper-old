#include "round.h"
#include "mines.h"
#include "player.h"
#include "print.h"
#include "uncover.h"

using namespace std;
using namespace minesweeper;

bool minesweeper::NextRoundPossible(Board board)
{
  return !AnyMineUncovered(board) && !AllSafeUncovered(board);
}

Board minesweeper::NextRound(Board board)
{
  Print(board);
  Print("Your move (row, column): ");

  return Uncover(board, RequestPlayerMove());
}

void minesweeper::EvaluationRound(Board board)
{
  Print(UncoverAllMines(board));

  if (AnyMineUncovered(board))
    return Print("You loose :-(\n");

  if (AllSafeUncovered(board))
    return Print("You win :-)\n");
}
