#pragma once
#include <string>
#include "optional.h"
#include "position.h"

namespace minesweeper
{
  using Move = Optional<Position>;
  Move ParseMove(std::string const& input);
}
