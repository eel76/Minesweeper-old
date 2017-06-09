#include "neighbors.h"

using namespace minesweeper;

Positions minesweeper::neighbors()
{
  // clang-format off
  return {
    { { -1, -1 }, { -1, 0 }, { -1, +1 },
      {  0, -1 },            {  0, +1 },
      { +1, -1 }, { +1, 0 }, { +1, +1 } }
  };
  // clang-format on
}
