#include "cells.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::positions(Board board)
{
  auto positions = Positions{};

  for (auto cell : board)
    positions.push_back(get<Position const>(cell));

  return positions;
}