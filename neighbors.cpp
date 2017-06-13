#include "neighbors.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::neighborOffsets()
{
  // clang-format off
    return { { { -1, -1 }, { -1, 0 }, { -1, +1 },
               {  0, -1 },            {  0, +1 },
               { +1, -1 }, { +1, 0 }, { +1, +1 } } };
  // clang-format on
}

Positions minesweeper::neighbors(Position position)
{
  auto offsets = neighborOffsets();
  transform(begin(offsets), end(offsets), begin(offsets),
            [=](auto offset) { return position + offset; });

  return offsets;
}