#pragma once
#include "board.h"
#include <functional>

namespace minesweeper
{
  using Move = std::function<Board(Board)>;
  Move reveal(Position position);
  Move toggle(Position position);
}