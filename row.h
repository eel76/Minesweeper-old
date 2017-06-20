#pragma once

namespace minesweeper
{
  enum struct Row { Invalid = -1 };
  enum struct RowOffset { Previous = -1, Current = 0, Next = +1 };
  Row shift(Row row, RowOffset offset);
}