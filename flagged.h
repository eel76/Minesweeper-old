#pragma once
#include "only.h"

namespace minesweeper {
  inline Filter marked() {
    return only(State::Marked);
  }
} // namespace minesweeper
