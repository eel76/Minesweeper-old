#pragma once
#include <utility>
#include "columns.h"
#include "rows.h"

namespace minesweeper
{
  using Position = std::pair<Row, Column>;
  Position shift(Position first, std::pair<int, int> steps);
}