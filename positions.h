#pragma once
#include "cells.h"
#include "position.h"

namespace minesweeper {
  using Positions = std::vector<Position>;
  Positions toPositions(Cells cells);
}
