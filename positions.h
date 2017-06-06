#pragma once
#include <vector>
#include "board.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions allPositions(Board board);
  Positions randomPositions(Positions positions, unsigned position_count);
}
