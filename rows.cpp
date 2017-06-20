#include "rows.h"
#include <algorithm>

using namespace minesweeper;

Row minesweeper::shift(Row row, RowOffset offset)
{
  return Row(int(row) + offset);
}

Rows minesweeper::rows(unsigned count)
{
  auto rows = Rows(count);
  generate(begin(rows), end(rows), [=]() mutable { return Row(--count); });

  return rows;
}