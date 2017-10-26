#include "columns.h"
#include <algorithm>

minesweeper::Columns minesweeper::operator"" _columns(unsigned long long count) {
  auto columns = Columns{ count };
  generate(begin(columns), end(columns),
           [index = 0]() mutable { return static_cast<Column>(index++); });

  return columns;
}
