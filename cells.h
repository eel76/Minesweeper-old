#pragma once
#include "board.h"
#include "positions.h"
#include "test.h"
#include <algorithm>

namespace minesweeper
{
  using std::get;

  using Cells = std::vector<Cell>;
  inline Cells operator|(Cells cells, Test test)
  {
    cells.erase(remove_if(begin(cells), end(cells), !test), end(cells));
    return cells;
  }

  inline Positions toPositions(Cells cells)
  {
    auto positions = Positions{};

    for (auto cell : cells)
      positions.push_back(get<Position>(cell));

    return positions;
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

  inline Test at(Positions positions)
  {
    return [=](auto cell) {
      return find(begin(positions), end(positions), get<Position>(cell)) != end(positions);
    };
  }
}