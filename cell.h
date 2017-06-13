#pragma once
#include <utility>

namespace minesweeper
{
  using Uncovered = bool;
  using Mines     = int;
  using Cell     = std::pair<Uncovered, Mines>;
  bool isMine(Cell cell);
}