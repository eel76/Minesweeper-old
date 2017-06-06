#include "neighbors.h"
#include <algorithm>
#include <iterator>

using namespace minesweeper;
using namespace std;

Positions minesweeper::neighborOffsets()
{
  return { { { -1, -1 }, { -1, 0 }, { -1, +1 },
	         {  0, -1 },            {  0, +1 },
	         { +1, -1 }, { +1, 0 }, { +1, +1 } }
  };
}

Positions minesweeper::cellNeighbors(Position position)
{
  auto neighbors = neighborOffsets();
  for_each(begin(neighbors), end(neighbors),
           [=](auto& neighbor) { neighbor = position + neighbor; });

  return neighbors;
}

Positions minesweeper::cellNeighbors(Board board, Position position)
{
  auto neighbors = cellNeighbors(position);

  auto on_board =
  remove_if(begin(neighbors), end(neighbors),
            [&](auto position) { return !contains(board, position); });
  return { begin(neighbors), on_board };
}
