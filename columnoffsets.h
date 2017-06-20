#pragma once
#include "column.h"
#include <vector>

namespace minesweeper
{
  using ColumnOffsets = std::vector<ColumnOffset>;
  ColumnOffsets columnOffsets();
}