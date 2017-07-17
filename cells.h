#pragma once
#include "board.h"
#include <vector>

namespace minesweeper
{
  using Cells = std::vector<Cell>;
  Cells cells(Board board);
  Cells shuffle(Cells cells);
}

#include "positions.h"
#include "test.h"

namespace minesweeper
{
  Cells operator|(Cells cells, Test test);

  Positions toPositions(Cells cells);

  using std::get;

  inline Test isDeadly()
  {
    return [](auto cell) { return isDeadly(get<Severity>(get<Threat>(cell))); };
  }

  inline Test isNegligible()
  {
    return
    [](auto cell) { return isNegligible(get<Severity>(get<Threat>(cell))); };
  }

  inline Test is(Visibility visibility)
  {
    return
    [=](auto cell) { return get<Visibility>(get<Threat>(cell)) == visibility; };
  }

  inline Test concealed()
  {
    return is(Visibility::Concealed);
  }

  inline Test recognized()
  {
    return is(Visibility::Recognized);
  }

  inline Test revealed()
  {
    return is(Visibility::Revealed);
  }

  inline Test oneOf(Positions positions)
  {
    return [=](auto cell) {
      return find(begin(positions), end(positions), get<Position>(cell)) != end(positions);
    };
  }

  inline Test neighborOf(Position position)
  {
    return [=](auto cell) {
      return maximumDistance(get<Position>(cell), position) == 1;
    };
  }
}