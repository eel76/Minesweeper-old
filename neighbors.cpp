#include "neighbors.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::neighbors(Position position)
{
  auto neighbors = Positions{
    { { -1, -1 }, { -1, 0 }, { -1, +1 }, { 0, -1 }, { 0, +1 }, { +1, -1 }, { +1, 0 }, { +1, +1 } }
  };
  transform(begin(neighbors), end(neighbors), begin(neighbors),
            [=](auto offset) { return position + offset; });

  return neighbors;
}
