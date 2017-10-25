#pragma once
#include "test.h"

namespace minesweeper {
  inline Filter isDeadly() {
    return [](auto cell) {
      return isDeadly(std::get<Severity>(std::get<Threat>(cell)));
    };
  }
} // namespace minesweeper
