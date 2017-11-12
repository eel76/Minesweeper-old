#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter only(State state) {
    return
    [=](auto cell) { return std::get<State>(std::get<Threat>(cell)) == state; };
  }
}
