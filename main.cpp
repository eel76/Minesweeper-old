#include "mines.h"
#include "move.h"
#include "print.h"
#include "uncover.h"

using namespace std;
using namespace minesweeper;

namespace
{
  auto constexpr kHeight = 9u;
  auto constexpr kWidth = 16u;
  auto constexpr kMineCount = 20u;

  auto Outcome(Board const& board)
  {
    if (AllSafeUncovered(board))
      return "You win :-)\n";

    return "You loose :-(\n";
  }
}

int main()
{
  auto board = SetMines(CreateBoard(kHeight, kWidth), kMineCount);

  while (!AnyMineUncovered(board) && !AllSafeUncovered(board))
  {
    Print(board);
    board = Uncover(board, PlayerMove(board));
  }

  Print(UncoverAllMines(board));
  Print(Outcome(board));

  return 0;
}
