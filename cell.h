#pragma once
#include <string>
#include <utility>
#include "state.h"

namespace minesweeper
{
  using Mines = int;
  using Cell  = std::pair<State, Mines>;
  std::string toString(Cell cell);
  Cell incrementMines(Cell cell, int increment);
  bool isMine(Cell cell);
}