#pragma once
#include "position.h"
#include <vector>

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions shuffle(Positions positions);
  Positions sample(Positions positions, size_t count);
}