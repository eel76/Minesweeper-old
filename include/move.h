#pragma once
#include "board.h"

#include <functional>

namespace minesweeper {
  using Move = std::function<Board(Board)>;
}
