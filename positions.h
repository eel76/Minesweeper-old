#pragma once
#include <vector>
#include "position.h"
#include "rows.h"
#include "columns.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions zipWith(Rows rows, int column);
  Positions join(std::vector<Positions> positionRanges);
  Positions cartesianProduct(Rows rows, Columns columns);
  Positions sample(Positions positions, size_t count);
}