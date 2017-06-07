#include "game.h"
#include "evaluation.h"
#include "preparation.h"
#include "round.h"

using namespace minesweeper;

void minesweeper::playGame(Size size, MineCount mineCount)
{
  auto board = layMines(makeBoard(size), mineCount);

  while (!gameLost(board) && !gameWon(board))
    board = playRound(board);

  evaluationRound(board);
}
