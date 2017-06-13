#pragma once
#include <vector>

namespace minesweeper
{
  enum struct Column : int { Curr = 0, Prev = -1, Next = 1, Invalid = -1 };
  Column operator+(Column first, Column second);
  using Columns = std::vector<Column>;
  Columns columns(unsigned count);
}