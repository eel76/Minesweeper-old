#include "neighbors.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::neighbors(Position position)
{
  auto offsets = Positions{
    { { -1, -1 }, { -1, 0 }, { -1, +1 }, { 0, -1 }, { 0, +1 }, { +1, -1 }, { +1, 0 }, { +1, +1 } }
  };
  transform(begin(offsets), end(offsets), begin(offsets),
            [=](auto offset) { return position + offset; });

  return offsets;
}
