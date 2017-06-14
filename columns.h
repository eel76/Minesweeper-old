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
  Column operator+(Column first, Column second);
  using Columns = std::vector<Column>;
  Columns columns(unsigned count);
}