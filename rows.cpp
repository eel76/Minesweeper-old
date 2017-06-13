#include "rows.h"
#include <algorithm>

using namespace minesweeper;

Row minesweeper::operator+(Row first, Row second)
{
  return Row(int(first) + int(second));
}

Rows minesweeper::rows(unsigned count)
{
  auto rows = Rows(count);
  generate(begin(rows), end(rows), [=]() mutable { return Row(--count); });

  return rows;
}