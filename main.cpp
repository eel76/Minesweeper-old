#include "mine.h"
#include "player.h"
#include "preparation.h"

int main() {
  using namespace minesweeper;

  auto const board  = minesLayed(makeBoard(20_rows, 40_columns), 100);
  auto const player = choosePlayer();

  play(player, board);
}
