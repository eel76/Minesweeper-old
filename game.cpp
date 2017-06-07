#include "game.h"
#include "preparation.h"
#include "round.h"

void minesweeper::playGame(Size size, MineCount mineCount)
{
  auto board = layMines(makeBoard(size), mineCount);

  while (roundPossible(board))
    board = playRound(board);

  evaluationRound(board);
}
