#pragma once
#include "positions.h"

namespace minesweeper
{
  Board uncoverCells(Board board, Positions positions);
  Board uncoverCell(Board board, Position position);
}
