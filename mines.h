#pragma once

namespace minesweeper
{
  enum Threat : unsigned { None = 0, AdjacentMine = 1, SubjacentMine = 9 };
}