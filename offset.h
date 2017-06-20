#pragma once
#include "column.h"
#include "row.h"
#include <utility>

namespace minesweeper
{
  using Offset = std::pair<RowOffset, ColumnOffset>;
  Offset currentOffset();
}