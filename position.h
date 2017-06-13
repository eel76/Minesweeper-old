#pragma once
#include <utility>
#include "columns.h"
#include "rows.h"

namespace minesweeper
{
  using Position = std::pair<Row, Column>;
  Position operator+(Position first, Position second);
}