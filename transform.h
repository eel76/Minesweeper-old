#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  std::vector<Threat> toCells(Positions positions, Board board);
  std::vector<std::string> toStrings(std::vector<Threat> cells);
}