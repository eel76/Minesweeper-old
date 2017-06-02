#pragma once
#include <map>
#include "position.h"
#include "size.h"
#include "state.h"

namespace minesweeper
{
  using Board = std::map<Position, State>;
  Board MakeBoard(Size size);
  bool Contains(Board const& board, Position const& position);
}
