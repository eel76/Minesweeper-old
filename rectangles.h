#pragma once
#include <array>
#include "rectangle.h"

namespace minesweeper
{
  using Rectangles = std::array<Rectangle, 3>;
  bool moveNonEmptyToFront(Rectangles::iterator begin, Rectangles::iterator end);
}
