#include "column.h"
#include <cmath>

int minesweeper::index(Column column) {
  return static_cast<int>(column);
}

int minesweeper::distance(Column first, Column second) {
  return std::abs(index(first) - index(second));
}
