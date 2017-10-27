#pragma once
#include "filter.h"
#include "positions.h"
#include <algorithm>

namespace minesweeper {
  inline Filter oneOf(Positions positions) {
    return [=](auto cell) {
      return find(begin(positions), end(positions), std::get<Position>(cell)) !=
             end(positions);
    };
  }
}
