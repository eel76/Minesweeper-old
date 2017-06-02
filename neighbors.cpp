#include "neighbors.h"
#include <algorithm>
#include <iterator>

using namespace minesweeper;
using namespace std;

Positions minesweeper::NeighborOffsets()
{
  return {
    { { -1, -1 }, { -1, 0 }, { -1, +1 }, { 0, -1 }, { 0, +1 }, { +1, -1 }, { +1, 0 }, { +1, +1 } }
  };
}

Positions minesweeper::Neighbors(Position const& position)
{
  auto neighbors = NeighborOffsets();
  for_each(begin(neighbors), end(neighbors),
           [=](auto& neighbor) { neighbor = position + neighbor; });

  return neighbors;
}

Positions minesweeper::Neighbors(Board const& board, Position const& position)
{
  auto neighbors = Neighbors(position);

  auto const on_board =
  remove_if(begin(neighbors), end(neighbors),
            [&](auto const& position) { return !Contains(board, position); });
  return { begin(neighbors), on_board };
}
