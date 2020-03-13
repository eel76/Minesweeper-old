#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter only(State specificState) {
    return [=](auto cell) { return state(threat(cell)) == specificState; };
  }
}
