#pragma once
#include <utility>
#include "mines.h"
#include "state.h"

namespace minesweeper
{
  using Cell = std::pair<State, MineCount>;
  Cell uncover(Cell cell);
  Cell incrementMines(Cell cell, int increment);
  bool isUncovered(Cell cell);
  bool containsMine(Cell cell);
}

#include <string>

namespace minesweeper
{
  std::string toString(Cell cell);
}