#pragma once
#include "column.h"
#include "row.h"

#include <utility>

namespace minesweeper {
  using Position = std::pair<Row, Column>;
  auto row(Position position) -> Row;
  auto column(Position position) -> Column;
  int maximumDistance(Position first, Position second);
}
