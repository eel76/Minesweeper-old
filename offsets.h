#pragma once
#include "offset.h"
#include <vector>

namespace minesweeper
{
  using Offsets = std::vector<Offset>;
  Offsets neighborOffsets();
}