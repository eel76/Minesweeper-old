#pragma once
#include <vector>
#include "board.h"

namespace minesweeper
{
  using Positions = std::vector<Position>;
  Positions allCells(Board board);
  Positions onlyMines(Board board, Positions positions);
  Positions shuffle(Positions positions);
}
