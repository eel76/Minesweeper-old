#pragma once
#include "offset.h"

namespace minesweeper
{
  using Position = std::pair<Row, Column>;
  Position shift(Position position, Offset offset);
}