#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper {
  Board marked(Board board, Positions positions);
  Board revealed(Board board, Positions positions);
}
