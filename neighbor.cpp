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

Positions minesweeper::validNeighbors(Board board, Position position)
{
  auto neighbors = allNeighbors(position);
  return { begin(neighbors), remove_if(begin(neighbors), end(neighbors), [=](auto position) {
             return !contains(board, position);
           }) };
}

Positions minesweeper::allNeighbors(Position position)
{
  auto neighbors = neighborOffsets();
  return { begin(neighbors),
           transform(begin(neighbors), end(neighbors), begin(neighbors),
                     [=](auto offset) { return position + offset; }) };
}
