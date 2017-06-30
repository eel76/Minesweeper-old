#pragma once
#include "board.h"
#include "positions.h"
#include <algorithm>
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

namespace minesweeper
{
  using std::get;

  using Cell = std::pair<Position, Threat>;

  using Test = std::function<bool(Cell)>;
  inline Test operator!(Test test)
  {
    return [=](auto cell) { return !test(cell); };
  }

  using Cells = std::vector<Cell>;

  inline Cells operator|(Cells cells, Test test)
  {
    cells.erase(remove_if(begin(cells), end(cells), !test), end(cells));
    return cells;
  }

  inline Cells cells(Board board)
  {
    return Cells{ begin(board), end(board) };
  }

  inline Test deadly()
  {
    return [](auto cell) {
      return get<Severity>(get<Threat>(cell)) >= Severity::Deadly;
    };
  }

  inline Test safe()
  {
    return [](auto cell) {
      return get<Severity>(get<Threat>(cell)) == Severity::Negligible;
    };
  }

  inline Test is(Visibility visibility)
  {
    return
    [=](auto cell) { return get<Visibility>(get<Threat>(cell)) == visibility; };
  }
}