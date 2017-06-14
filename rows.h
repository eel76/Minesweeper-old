#pragma once
#include <vector>

namespace minesweeper
{
  enum struct Row : unsigned {
    Curr    = 0u,
    Prev    = 0u - 1u,
    Next    = 1u,
    Invalid = ~0u
  };
  Row operator+(Row first, Row second);
  using Rows = std::vector<Row>;
  Rows rows(unsigned count);
}