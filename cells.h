#pragma once
#include "cell.h"
#include <vector>

namespace minesweeper {
  using Cells = std::vector<Cell>;
  Cells cells(Board board);
  Cells shuffle(Cells cells);
}
