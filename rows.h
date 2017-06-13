#pragma once
#include <vector>

namespace minesweeper
{
  enum struct Row : int { Curr = 0, Prev = -1, Next = 1, Invalid = -1 };
  Row operator+(Row first, Row second);
  using Rows = std::vector<Row>;
  Rows rows(unsigned count);
}