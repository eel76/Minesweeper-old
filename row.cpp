#include "row.h"

using namespace minesweeper;

RowCount minesweeper::operator""_rows(unsigned long long rowCount)
{
  return static_cast<RowCount>(rowCount);
}
