#include "board.h"
#include "mine.h"
#include "preparation.h"

auto minesweeper::makeBoard() -> Board {
  return minesLayed(setupBoard(10_rows, 10_columns), 10);
}
