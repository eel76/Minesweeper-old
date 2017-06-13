#pragma once
#include <map>
#include "position.h"
#include "cell.h"

namespace minesweeper
{
  using Board = std::map<Position, Cell>;
}