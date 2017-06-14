#pragma once
#include "positions.h"
#include <string>

namespace minesweeper
{
  Positions join(std::vector<Positions> positionLists);
  std::string join(std::vector<std::string> strings);
}