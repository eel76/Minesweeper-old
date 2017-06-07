#include "neighbor.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::neighborOffsets()
{
  // clang-format off
  return {
    { { -1, -1 }, { -1, 0 }, { -1, +1 },
      {  0, -1 },            {  0, +1 },
      { +1, -1 }, { +1, 0 }, { +1, +1 } }
  };
  // clang-format on
}

Positions minesweeper::neighborPositions(Board board, Position position)
{
  auto neighbors = neighborOffsets();
  transform(begin(neighbors), end(neighbors), begin(neighbors),
            [=](auto offset) { return position + offset; });

  return { begin(neighbors), remove_if(begin(neighbors), end(neighbors), [=](auto position) {
             return !contains(board, position);
           }) };
}
