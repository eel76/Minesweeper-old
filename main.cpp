#include "game.h"
#include "move.h"
#include "preparation.h"

using namespace minesweeper;

int main()
{
  auto board  = makeBoard(Dimensions{ columns(10), rows(10) }, 10);
  auto player = computerPlayer();

  while (!gameLost(board) && !gameWon(board))
    board = gameRound(board, player);

  evaluateGame(board);
  return 0;
}