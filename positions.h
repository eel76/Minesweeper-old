#pragma once
#include <vector>
#include "position.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions add(Positions positions, Position offset);
  Positions shuffle(Positions positions);
}
