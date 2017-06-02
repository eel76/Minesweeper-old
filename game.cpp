#include "game.h"
#include "mines.h"
#include "round.h"

using namespace std;
using namespace minesweeper;

void minesweeper::PlayGame(Size size, MineCount mineCount)
{
  auto board = LayMines(MakeBoard(size), mineCount);

  while (IsRoundPossible(board))
    board = PlayRound(board);

  EndRound(board);
}
