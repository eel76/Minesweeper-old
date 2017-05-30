#pragma once
#include <vector>
#include "board.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions NeighborPositions(Board const& board, Position const& position);
  Positions RandomPositions(Board const& board, unsigned position_count);
}
