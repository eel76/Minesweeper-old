#pragma once
#include <vector>
#include "position.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions sample(Positions positions, size_t count);
}
