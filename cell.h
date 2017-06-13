#pragma once
#include <utility>

namespace minesweeper
{
  enum State { Covered, Uncovered };
  using Mines     = int;
  using Cell     = std::pair<State, Mines>;
  bool isMine(Cell cell);
}