#pragma once
#include "board.h"
#include "dimensions.h"
#include "mine.h"

namespace minesweeper
{
  Board prepareBoard(Dimensions dimensions, MineCount mineCount);
}