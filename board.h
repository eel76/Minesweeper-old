#pragma once
#include "position.h"
#include "threat.h"
#include <map>

namespace minesweeper
{
  using Cell  = std::pair<Position, Threat>;
  using Board = std::map<Position, Threat>;
}