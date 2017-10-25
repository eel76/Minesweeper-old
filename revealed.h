#pragma once
#include "only.h"

namespace minesweeper {
  inline Filter revealed() {
    return only(State::Revealed);
  }
} // namespace minesweeper
