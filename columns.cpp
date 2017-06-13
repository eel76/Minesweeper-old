#include "columns.h"
#include <algorithm>

using namespace minesweeper;

Column minesweeper::operator+(Column first, Column second)
{
  return Column(int(first) + int(second));
}

Columns minesweeper::columns(unsigned count)
{
  auto columns = Columns(count);
  generate(begin(columns), end(columns),
           [=]() mutable { return Column(--count); });

  return columns;
}