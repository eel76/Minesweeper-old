#include "neighbors.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::neighborOffsets()
{
  // clang-format off
    return { { { Row::Prev, Column::Prev }, { Row::Prev, Column::Curr }, { Row::Prev, Column::Next },
               { Row::Curr, Column::Prev },                              { Row::Curr, Column::Next },
               { Row::Next, Column::Prev }, { Row::Next, Column::Curr }, { Row::Next, Column::Next } } };
  // clang-format on
}

Positions minesweeper::neighbors(Position position)
{
  auto offsets = neighborOffsets();
  transform(begin(offsets), end(offsets), begin(offsets),
            [=](auto offset) { return position + offset; });

  return offsets;
}