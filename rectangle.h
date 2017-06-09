#pragma once
#include <utility>
#include "position.h"
#include "size.h"

namespace minesweeper
{
  using Rectangle = std::pair<Position, Position>;
  Rectangle makeRectangle(Size size);
  bool isEmpty(Rectangle rectangle);
}
