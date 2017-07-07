#include "cells.h"
#include <algorithm>
#include <random>

minesweeper::Cells minesweeper::operator|(Cells cells, Test test)
{
  cells.erase(remove_if(begin(cells), end(cells), !test), end(cells));
  return cells;
}

minesweeper::Positions minesweeper::toPositions(Cells cells)
{
  auto positions = Positions{};

  for (auto cell : cells)
    positions.push_back(get<Position>(cell));

  return positions;
}

minesweeper::Cells minesweeper::cells(Board board)
{
  return Cells{ begin(board), end(board) };
}

minesweeper::Cells minesweeper::shuffle(Cells cells)
{
  shuffle(begin(cells), end(cells), std::ranlux48{ std::random_device{}() });
  return cells;
}