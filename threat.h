#pragma once
#include <string>

namespace minesweeper
{
  enum Threat { None = 0, AdjacentMine = 1, Mine = 9 };
  std::string toString(Threat threat);
}