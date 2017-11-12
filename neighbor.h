#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter neighborOf(Position position) {
    return [=](auto cell) {
      return maximumDistance(std::get<Position>(cell), position) == 1;
    };
  }
}
