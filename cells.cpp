#include "cells.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::allCells(Board board)
{
  auto positions = Positions{};

  for (auto cell : board)
    positions.push_back(get<Position const>(cell));

  return positions;
}

Positions minesweeper::allMines(Board board)
{
  auto positions = allCells(board);
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return !isMine(board.at(position));
           }) };
}