#pragma once
#include "positions.h"
#include <map>

namespace minesweeper {
  std::map<Row, Positions> byRow(Positions positions);
}
