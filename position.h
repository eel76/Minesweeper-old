#pragma once
#include "column.h"
#include "row.h"
#include <utility>

namespace minesweeper {
  using Position = std::pair<Row, Column>;
  int maximumDistance(Position first, Position second);
}
