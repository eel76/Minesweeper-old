#pragma once
#include "filter.h"

namespace minesweeper {
  inline Filter take(unsigned count) {
    return [count, seen = 0u](auto cell) mutable { return ++seen <= count; };
  }
}
