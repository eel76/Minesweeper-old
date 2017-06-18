#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Board toggleFlag(Board board, Positions positions);
  Board uncover(Board board, Positions positions);
}