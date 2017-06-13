#pragma once
#include <vector>

namespace minesweeper
{
  enum Column : unsigned {};
  using Columns = std::vector<Column>;
  Columns columns(unsigned count);
}