#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Board uncover(Board board, Position position);
  Board uncover(Board board, Positions positions);
}
