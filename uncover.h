#pragma once
#include "positions.h"

namespace minesweeper
{
  bool isCovered(Board board, Position position);
  Board uncoverCell(Board board, Position position);
  Board uncoverCells(Board board, Positions positions);
}
