#pragma once
#include "board.h"
#include "cells.h"

namespace minesweeper {
  Board mineLayed(Board board, Position position);
  Board minesLayed(Board board, Cells cells);
  Board minesLayed(Board board, unsigned count);
}
