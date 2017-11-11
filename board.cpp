#include "board.h"
#include "mine.h"
#include "preparation.h"

auto minesweeper::makeBoard() -> Board {
  return minesLayed(setupBoard(20_rows, 40_columns), 100);
}
