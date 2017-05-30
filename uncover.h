#pragma once
#include "move.h"
#include "positions.h"

namespace minesweeper
{
  Board Uncover(Board board, Positions positions);
  Board Uncover(Board board, Move move);
}
