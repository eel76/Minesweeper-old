#include "column.h"

int minesweeper::index(Column column)
{
  return int(column);
}

std::string minesweeper::to_string(Column column)
{
  return std::to_string(index(column));
}