#pragma once
#include "board.h"
#include "positions.h"
#include <functional>

namespace minesweeper
{
  using Predicate = std::function<bool(Position)>;
  Predicate operator!(Predicate predicate);
  Positions operator|(Positions positions, Predicate predicate);

  Predicate within(Board board);
  Predicate deadly(Board board);
  Predicate revealed(Board board);
  Predicate covered(Board board);
  Predicate recognized(Board board);
  Predicate safe(Board board);
}