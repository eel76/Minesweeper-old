#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter isNegligible() {
    return [](auto cell) { return isNegligible(std::get<Threat>(cell)); };
  }
}
