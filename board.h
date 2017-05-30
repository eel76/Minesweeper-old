#pragma once
#include <map>
#include "position.h"
#include "state.h"

namespace minesweeper
{
  using Board = std::map<Position, State>;
  Board CreateBoard (unsigned height, unsigned width);
}
