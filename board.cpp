#include "board.h"
#include "mine.h"
#include "preparation.h"

auto minesweeper::setupBoard() -> Board {
  return minesLayed(makeBoard(20_rows, 40_columns), 100);
}
