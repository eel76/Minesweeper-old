#include "row.h"
#include <cmath>

int minesweeper::index(Row row) {
  return static_cast<int>(row);
}

int minesweeper::distance(Row first, Row second) {
  return std::abs(index(first) - index(second));
}
