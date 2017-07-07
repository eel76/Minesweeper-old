#include "row.h"

int minesweeper::index(Row row)
{
  return int(row);
}

int minesweeper::distance(Row first, Row second)
{
  return std::abs(index(first) - index(second));
}

std::string minesweeper::to_string(Row row)
{
  return std::to_string(index(row));
}