#pragma once
#include "positions.h"

namespace minesweeper
{
  Board uncoverCell(Board board, Position position);
  Board uncoverCells(Board board, Positions positions);
  Board uncoverMines(Board board);
}
