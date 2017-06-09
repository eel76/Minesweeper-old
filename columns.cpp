#include "columns.h"

using namespace minesweeper;

ColumnCount minesweeper::operator""_columns(unsigned long long columnCount)
{
  return static_cast<ColumnCount>(columnCount);
}
