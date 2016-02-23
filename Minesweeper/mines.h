#pragma once
#include "board.h"

namespace minesweeper
{
Board SetMines(Board board, unsigned mine_count);
Board UncoverAllMines(Board board);
bool AnyMineUncovered(Board const& board);
bool AllSafeUncovered(Board const& board);
}
