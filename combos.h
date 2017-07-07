#pragma once
#include "columns.h"
#include "positions.h"
#include "rows.h"

namespace minesweeper
{
  Positions allCombos(Rows rows, Column column);
  Positions allCombos(Rows rows, Columns columns);
}