#pragma once
#include "position.h"
#include <vector>

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions shuffle(Positions positions);
  Positions first(size_t count, Positions positions);
}