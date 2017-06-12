#pragma once
#include <vector>
#include "position.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions shuffle(Positions positions);
}
