#pragma once
#include "board.h"
#include "positions.h"
#include <functional>

namespace minesweeper
{
  using Predicate = std::function<bool(Position)>;
  Predicate operator!(Predicate predicate);
  Positions operator|(Positions positions, Predicate predicate);

  using Filter = std::function<bool(Board, Position)>;
  Filter operator!(Filter filter);

  using Range = std::pair<Board, Positions>;
  Range operator|(Range range, Filter filter);

  Range all(Board board);

  Filter inBounds();
  Filter deadly();
  Filter revealed();
  Filter covered();
  Filter marked();
  Filter noThreat();
}

namespace minesweeper
{
  Predicate within(Board board);
  Predicate deadly(Board board);
  Predicate revealed(Board board);
  Predicate covered(Board board);
  Predicate marked(Board board);
  Predicate minimalThreat(Board board);
}