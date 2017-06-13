#include "rows.h"
#include <numeric>

using namespace minesweeper;

Rows minesweeper::rows(size_t count)
{
  auto rows = Rows(count);
  iota(begin(rows), end(rows), 0);

  return rows;
}