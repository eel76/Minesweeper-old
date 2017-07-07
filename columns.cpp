#include "columns.h"
#include <algorithm>

minesweeper::Columns minesweeper::operator"" _columns(unsigned long long count)
{
  auto columns = Columns(count);
  generate(begin(columns), end(columns),
           [=]() mutable { return static_cast<Column>(--count); });

  return columns;
}