#pragma once
#include <string>

namespace minesweeper
{
  enum struct Column { Invalid = -1 };
  int         index(Column column);
  std::string to_string(Column column);
}