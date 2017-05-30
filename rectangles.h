#pragma once
#include <array>
#include "rectangle.h"

namespace minesweeper
{
  using Rectangles = std::array<Rectangle, 3>;
  bool MoveNonEmptyToFront(Rectangles::iterator begin, Rectangles::iterator end);
}
