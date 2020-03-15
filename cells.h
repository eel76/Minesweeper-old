#pragma once
#include "cell.h"
#include <vector>

namespace minesweeper {
  using Cells = std::vector<Cell>;
  auto cells(Board board) -> Cells;
  auto shuffle(Cells cells) -> Cells;
}
