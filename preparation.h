#pragma once
#include "board.h"
#include "columns.h"
#include "rows.h"

namespace minesweeper {
  Board setupBoard(Rows rows, Columns columns);
  Board setupMines(unsigned count);
}
