#pragma once
#include "board.h"
#include "mine.h"
#include "size.h"

namespace minesweeper
{
  Board makeBoard(Size size);
  Board layMines(Board board, MineCount mineCount);
}
