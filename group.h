#pragma once
#include <map>
#include "positions.h"

namespace minesweeper
{
  std::map<Row, Positions> groupRows(Positions positions);
}