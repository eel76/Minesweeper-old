#include "game.h"
#include "move.h"
#include "preparation.h"

using namespace minesweeper;

int main()
{
  auto player = choosePlayer();
  auto board  = makeBoard(Dimensions{ columns(40), rows(20) }, 100);

  while (gameUndecided(board))
    board = playRound(board, player);

  evaluateGame(board);
  return 0;
}