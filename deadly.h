#pragma once
#include "test.h"

namespace minesweeper {
  inline Filter deadly() {
    return
    [](auto cell) { return deadly(std::get<Severity>(std::get<Threat>(cell))); };
  }
}
