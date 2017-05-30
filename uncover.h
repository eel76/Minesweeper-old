#pragma once
#include "board.h"

namespace minesweeper
{
  Board Uncover(Board board, Position const& starting_position);
}
