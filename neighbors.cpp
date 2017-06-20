#include "neighbors.h"
#include "offsets.h"

namespace minesweeper
{
  Positions neighborPositions(Position position)
  {
    auto neighbors = Positions{};

    for (auto offset : neighborOffsets())
      neighbors.push_back(shift(position, offset));

    return neighbors;
  }
}