#include "mined.h"
#include "play.h"
#include "preparation.h"

int main() {
  using namespace minesweeper;

  auto const board  = mined(makeBoard(20_rows, 40_columns), 100);
  auto const player = choosePlayer();

  play(board, player);
}
