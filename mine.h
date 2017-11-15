#pragma once
#include "board.h"

namespace minesweeper {
  Board mineLayed(Board board, Position position);
  Board minesLayed(Board board, unsigned count);
}
