#include "row.h"

int minesweeper::index(Row row)
{
  return int(row);
}

std::string minesweeper::to_string(Row row)
{
  return std::to_string(index(row));
}