#include "column.h"
#include <cmath>

auto minesweeper::index(Column column) -> int {
  return static_cast<int>(column);
}

auto minesweeper::distance(Column first, Column second) -> int {
  return std::abs(index(first) - index(second));
}
