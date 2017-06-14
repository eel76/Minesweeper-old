#pragma once
#include "board.h"
#include "dimensions.h"

namespace minesweeper
{
  Board makeBoard(Dimensions dimensions, unsigned mineCount);
}