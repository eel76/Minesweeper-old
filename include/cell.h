#pragma once
#include "board.h"

namespace minesweeper {
  struct Cell
  {
    Board::key_type position;
    Board::mapped_type threat;  
  };
  auto position(Cell cell) -> Position;
  auto threat(Cell cell) -> Threat;
}
