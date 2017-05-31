#pragma once
#include <utility>

namespace minesweeper
{
  using Position = std::pair<int, int>;
  Position operator+(Position const& first, Position const& second);
  bool operator<(Position const& first, Position const& second);
}
