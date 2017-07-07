#pragma once
#include "position.h"
#include <vector>

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions first(size_t count, Positions positions);
}