#pragma once
#include "test.h"

namespace minesweeper {
  inline Filter take(unsigned count) {
    return [count, tested = 0u](auto cell) mutable { return ++tested <= count; };
  }
}
