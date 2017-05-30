#pragma once
#include <utility>
#include "position.h"

namespace minesweeper
{
  using Rectangle = std::pair<Position, Position>;
  Rectangle WithoutFirstRow (Rectangle rectangle);
  Rectangle FirstRowWithoutFirstColumn (Rectangle rectangle);
}
