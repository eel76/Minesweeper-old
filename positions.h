#pragma once
#include <vector>
#include "board.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions AllPositions(Board const& board);
  Positions RandomPositions(Positions positions, unsigned position_count);
}
