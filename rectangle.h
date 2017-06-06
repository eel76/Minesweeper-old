#pragma once
#include <utility>
#include "position.h"

namespace minesweeper
{
  using Rectangle = std::pair<Position, Position>;
  Rectangle withoutFirstRow(Rectangle rectangle);
  Rectangle firstRowWithoutFirstColumn(Rectangle rectangle);
}
