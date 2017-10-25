#pragma once
#include "only.h"

namespace minesweeper {
  inline Filter concealed() {
    return only(State::Concealed);
  }
} // namespace minesweeper
