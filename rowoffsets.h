#pragma once
#include <vector>
#include "row.h"

namespace minesweeper
{
  using RowOffsets = std::vector<RowOffset>;
  RowOffsets rowOffsets();
}