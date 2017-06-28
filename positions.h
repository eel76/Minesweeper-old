#pragma once
#include "columns.h"
#include "position.h"
#include "rows.h"
#include <vector>

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions allCombos(Rows rows, Column column);
  Positions allCombos(Rows rows, Columns columns);
  Positions sample(Positions positions, size_t count);
}