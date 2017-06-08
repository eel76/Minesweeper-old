#pragma once
#include <vector>
#include "board.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions allCells(Board board);
  Positions allMines(Board board);
  Positions shuffle(Positions positions);
}
