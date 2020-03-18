#pragma once
#include "move.h"
#include <functional>

namespace minesweeper {
  using Player = std::function<Move(Board)>;
}
