#pragma once
#include <vector>

namespace minesweeper
{
  enum Row : unsigned {};
  using Rows = std::vector<Row>;
  Rows rows(unsigned count);
}