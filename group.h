#pragma once
#include <map>
#include "positions.h"

namespace minesweeper
{
  std::map<int, Positions> groupRows(Positions positions);
}
