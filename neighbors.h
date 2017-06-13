#pragma once
#include "positions.h"

namespace minesweeper
{
  Positions neighborOffsets();
  Positions neighbors(Position position);
}