#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Board toggleMark(Board board, Positions positions);
  Board uncover(Board board, Positions positions);
}