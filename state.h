#pragma once
#include <string>
#include <utility>

namespace minesweeper
{
  using Uncovered = bool;
  using MineCount = int;
  using State = std::pair<Uncovered, MineCount>;
  std::string ToString(State const& state);
}
