#pragma once
#include <string>

namespace minesweeper
{
  enum struct Column { Invalid = -1 };
  int         index(Column column);
  std::string to_string(Column column);
}

namespace minesweeper
{
  enum struct ColumnOffset { Previous = -1, Current = 0, Next = +1 };
  Column shift(Column column, ColumnOffset offset);
}