#include "mined.h"
#include "play.h"
#include "player/choose.h"
#include "preparation.h"

int main() {
  using namespace minesweeper;

  auto const board = mined(makeBoard(20_rows, 40_columns), 100);
  play(board, player::choose());
}
