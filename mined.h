#pragma once
#include "board.h"

namespace minesweeper {
  Board mined(Board board, Position position);
  Board mined(Board board, unsigned count);
}
