#include "columns.h"
#include <numeric>

using namespace minesweeper;

Columns minesweeper::columns(size_t count)
{
  auto columns = Columns(count);
  iota(begin(columns), end(columns), 0);

  return columns;
}