#pragma once
#include "position.h"
#include "threat.h"
#include <utility>

namespace minesweeper
{
  using Cell = std::pair<Position, Threat>;
}