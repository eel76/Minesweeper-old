#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter only(State state) {
    return
    [=](auto cell) { return std::get<State>(threat(cell)) == state; };
  }
}
