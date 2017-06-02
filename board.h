#pragma once
#include <map>
#include "position.h"
#include "state.h"

namespace minesweeper
{
  using Board = std::map<Position, State>;
  bool Contains(Board const& board, Position const& position);
}
