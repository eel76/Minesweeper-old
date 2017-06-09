#include "cells.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::allCells(Board board)
{
  auto positions = Positions{ board.size() };
  transform(begin(board), end(board), begin(positions),
            [](auto cell) { return get<Position const>(cell); });

  return positions;
}
