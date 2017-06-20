#pragma once

namespace minesweeper
{
  enum struct Column { Invalid = -1 };
  enum struct ColumnOffset { Previous = -1, Current = 0, Next = +1 };
  Column shift(Column column, ColumnOffset offset);
}