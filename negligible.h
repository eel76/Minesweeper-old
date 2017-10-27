#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter isNegligible() {
    return [](auto cell) {
      return isNegligible(std::get<Severity>(std::get<Threat>(cell)));
    };
  }
} // namespace minesweeper
