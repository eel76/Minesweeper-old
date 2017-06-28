#pragma once
#include "board.h"
#include "positions.h"
#include <functional>

namespace minesweeper
{
  using Predicate = std::function<bool(Position)>;
  Predicate operator!(Predicate predicate);

  Predicate within(Board board);
  Predicate deadly(Board board);
  Predicate revealed(Board board);
  Predicate covered(Board board);
  Predicate marked(Board board);
  Predicate minimalThreat(Board board);

  Positions operator|(Positions positions, Predicate predicate);
}