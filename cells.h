#pragma once
#include "board.h"
#include <vector>

namespace minesweeper {
  using Cells = std::vector<Cell>;
  Cells cells(Board board);
  Cells shuffled(Cells cells);
}
