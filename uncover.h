#pragma once
#include "positions.h"

namespace minesweeper
{
  Board Uncover(Board board, Positions positions);
  Board Uncover(Board board, Position position);
}
