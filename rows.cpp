#include "rows.h"
#include <algorithm>

auto minesweeper::operator"" _rows(unsigned long long count) -> Rows {
  auto rows = Rows(count);
  generate(begin(rows), end(rows),
           [index = 0]() mutable { return static_cast<Row>(index++); });

  return rows;
}
