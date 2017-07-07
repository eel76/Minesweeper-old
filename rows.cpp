#include "rows.h"
#include <algorithm>

minesweeper::Rows minesweeper::operator"" _rows(unsigned long long count)
{
  auto rows = Rows(count);
  generate(begin(rows), end(rows),
           [=]() mutable { return static_cast<Row>(--count); });

  return rows;
}