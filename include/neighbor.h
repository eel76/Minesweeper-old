#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter neighborOf(Cell cell) {
    return [=](auto neighbor) {
      return maximumDistance(position(neighbor), position(cell)) == 1;
    };
  }
}
