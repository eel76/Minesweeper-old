#include "columns.h"
#include <algorithm>

using namespace minesweeper;

Column minesweeper::shift(Column column, int steps)
{
  return Column(unsigned(column) + steps);
}

Columns minesweeper::columns(unsigned count)
{
  auto columns = Columns(count);
  generate(begin(columns), end(columns),
           [=]() mutable { return Column(--count); });

  return columns;
}