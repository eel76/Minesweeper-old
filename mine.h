#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper {
  Board mineLayed(Board board, Position position);
  Board minesLayed(Board board, Positions positions);
  Board minesLayed(Board board, unsigned count);
}
