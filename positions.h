#pragma once
#include <vector>
#include "columns.h"
#include "position.h"
#include "rows.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions zipWith(Rows rows, Column column);
  Positions join(std::vector<Positions> positionRanges);
  Positions cartesianProduct(Rows rows, Columns columns);
  Positions sample(Positions positions, size_t count);
}