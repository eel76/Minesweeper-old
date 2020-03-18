#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter isDeadly() {
    return [](auto cell) { return isDeadly(threat(cell)); };
  }
}
