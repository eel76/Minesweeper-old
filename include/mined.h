#pragma once
#include "board.h"
#include "cell.h"

namespace minesweeper {
  Board mined(Board board, Cell cell);
  Board mined(Board board, unsigned count);
}
