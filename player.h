#pragma once
#include "position.h"

namespace minesweeper
{
  enum struct Action : unsigned { Unknown, Uncover, ToggleFlag };
  using Move = std::pair<Action, Position>;
  Position playerMove();
}