#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  std::vector<Cell> toCells(Positions positions, Board board);
  std::vector<std::string> toStrings(std::vector<Cell> cells);
}