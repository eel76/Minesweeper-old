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