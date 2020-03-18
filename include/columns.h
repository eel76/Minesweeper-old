#pragma once
#include "column.h"
#include <vector>

namespace minesweeper
{
  using Columns = std::vector<Column>;
  Columns operator"" _columns(unsigned long long count);
}