#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Board uncover(Board board, Positions positions);
  State uncover(State state);
}