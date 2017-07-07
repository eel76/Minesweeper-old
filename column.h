#pragma once
#include <string>

namespace minesweeper
{
  enum struct Column { Invalid = -1 };
  int index(Column column);
  int distance(Column first, Column second);
  std::string to_string(Column column);
}