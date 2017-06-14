#pragma once
#include <utility>
#include "mines.h"
#include "state.h"

namespace minesweeper
{
  using Cell = std::pair<State, Threat>;
  Cell uncover(Cell cell);
  Cell threaten(Cell cell, Threat threat);
  bool isUncovered(Cell cell);
  bool containsMine(Cell cell);
}

#include <string>

namespace minesweeper
{
  std::string toString(Cell cell);
}