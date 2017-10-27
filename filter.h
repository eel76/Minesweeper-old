#pragma once
#include "cells.h"
#include <functional>

namespace minesweeper {
  using Filter = std::function<bool(Cell)>;
  Filter operator!(Filter test);
  Cells  operator|(Cells cells, Filter filter);
}
