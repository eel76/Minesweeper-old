#pragma once
#include "action.h"
#include "position.h"

namespace minesweeper
{
  using Move = std::pair<Action, Position>;
  Move playerMove();
}