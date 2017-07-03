#include "cells.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Cells minesweeper::operator|(Cells cells, Test test)
{
  cells.erase(remove_if(begin(cells), end(cells), !test), end(cells));
  return cells;
}

Positions minesweeper::toPositions(Cells cells)
{
  auto positions = Positions{};

  for (auto cell : cells)
    positions.push_back(get<Position>(cell));

  return positions;
}

Cells minesweeper::cells(Board board)
{
  return Cells{ begin(board), end(board) };
}