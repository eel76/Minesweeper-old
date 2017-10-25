#pragma once
#include "only.h"

namespace minesweeper {
  inline Filter flagged() {
    return only(State::Marked);
  }
} // namespace minesweeper
