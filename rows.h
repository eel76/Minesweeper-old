#pragma once
#include <vector>
#include "row.h"

namespace minesweeper
{
  using Rows = std::vector<Row>;
  Rows rows(unsigned count);
}