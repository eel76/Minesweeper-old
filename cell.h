#pragma once
#include <utility>
#include "state.h"

namespace minesweeper
{
  using Mines = int;
  using Cell  = std::pair<State, Mines>;
  bool isMine(Cell cell);
}