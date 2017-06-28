#pragma once
#include "board.h"
#include <functional>

namespace minesweeper
{
  using Predicate = std::function<bool(Position)>;
  Predicate operator!(Predicate predicate)
  {
    return [=](auto position) { return !predicate(position); };
  }

  Predicate within(Board board);
  Predicate deadly();
  Predicate revealed();
  Predicate covered();
  Predicate marked();

  Positions operator|(Positions positions, Predicate predicate)
  {
    positions.erase(remove_if(begin(positions), end(positions),
                              [=](auto position) { return !predicate(position); }),
                    end(positions));
    return positions;
  }
}