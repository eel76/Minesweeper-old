#pragma once
#include <vector>

namespace minesweeper
{
  enum struct Column : unsigned {
    Curr    = 0u,
    Prev    = 0u - 1u,
    Next    = 1u,
    Invalid = ~0u
  };
  using Columns = std::vector<Column>;
  Column shift(Column column, int steps);
  Columns columns(unsigned count);
}