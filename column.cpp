#include "column.h"

using namespace minesweeper;

int minesweeper::index(Column column)
{
  return int(column);
}

std::string minesweeper::to_string(Column column)
{
  return std::to_string(index(column));
}

Column minesweeper::shift(Column column, ColumnOffset offset)
{
  return Column(index(column) + int(offset));
}