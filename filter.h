#pragma once
#include "board.h"
#include "positions.h"
#include <algorithm>
#include <functional>

namespace minesweeper
{
  // Positions withinBounds(Positions positions, Board board);
  // Positions withMine(Positions positions, Board board);
  // Positions coveredCells(Positions positions, Board board);
  // Positions uncoveredCells(Positions positions, Board board);
  // Positions markedCells(Positions positions, Board board);
  // Positions unmarkedCells(Positions positions, Board board);
  // Positions minimumThreat(Positions positions, Board board);

  using Predicate = std::function<bool(Position)>;
  Predicate operator!(Predicate predicate);

  Predicate within(Board board);
  Predicate deadly(Board board);
  Predicate uncovered(Board board);
  Predicate covered(Board board);
  Predicate marked(Board board);
  Predicate minimumThreat(Board board);

  Positions operator|(Positions positions, Predicate predicate);
}