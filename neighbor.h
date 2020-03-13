#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter neighborOf(Position p) {
    return [=](auto cell) {
      return maximumDistance(position(cell), p) == 1;
    };
  }
}
