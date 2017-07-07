#pragma once
#include "row.h"
#include <vector>

namespace minesweeper
{
  using Rows = std::vector<Row>;
  Rows operator"" _rows(unsigned long long count);
}