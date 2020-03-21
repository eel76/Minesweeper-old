#include "mined.h"
#include "game/play.h"
#include "player/choose.h"
#include "preparation.h"

int main() {
  using namespace minesweeper;

  auto const board = mined(makeBoard(9_rows, 9_columns), 10);
  game::play(player::choose(), board);
}
