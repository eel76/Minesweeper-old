#pragma once
#include "columns.h"
#include "positions.h"
#include "rows.h"

namespace minesweeper
{
  Positions combos(Rows rows, Column column);
  Positions combos(Rows rows, Columns columns);
}