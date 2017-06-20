#pragma once
#include <vector>
#include "column.h"

namespace minesweeper
{
  using Columns = std::vector<Column>;
  Columns columns(unsigned count);
}