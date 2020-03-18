#include "row.h"
#include <cmath>

auto minesweeper::index(Row row) -> int {
  return static_cast<int>(row);
}

auto minesweeper::distance(Row first, Row second) -> int {
  return std::abs(index(first) - index(second));
}
