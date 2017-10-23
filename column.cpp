#include "column.h"

int minesweeper::index(Column column)
{
  return static_cast<int>(column);
}

int minesweeper::distance(Column first, Column second)
{
  return std::abs(index(first) - index(second));
}

std::string minesweeper::to_string(Column column)
{
  return std::to_string(index(column));
}