#pragma once
#include "board.h"
#include "positions.h"

namespace minesweeper
{
  Board changeGuess(Board board, Positions positions);
  Board reveal(Board board, Positions positions);
}