#pragma once
#include <utility>

namespace minesweeper
{
  using Uncovered = bool;
  using Mines     = int;
  using State     = std::pair<Uncovered, Mines>;
  bool isMine(State state);
}