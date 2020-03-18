#pragma once
#include "cell.h"
#include <vector>

namespace minesweeper {
  using Cells = std::vector<Cell>;
  auto cellsOf(Board board) -> Cells;
}
