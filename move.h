#pragma once
#include "optional.h"
#include "position.h"

namespace minesweeper
{
  using Move = Optional<Position>;
  Move PlayerMove();
}
