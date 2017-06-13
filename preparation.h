#pragma once
#include "board.h"
#include "mine.h"
#include "size.h"

namespace minesweeper
{
  Board prepareBoard(Size size, MineCount mineCount);
}