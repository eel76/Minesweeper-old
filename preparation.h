#pragma once
#include "board.h"
#include "mine.h"
#include "size.h"

namespace minesweeper
{
  Board MakeBoard(Size size);
  Board LayMines(Board board, MineCount mineCount);
}
