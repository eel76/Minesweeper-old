#pragma once
#include <utility>

namespace minesweeper
{
  using Position = std::pair<int, int>;
  Position operator+(Position first, Position second);
}