#pragma once
#include "cell.h"
#include <functional>

namespace minesweeper
{
  using Test = std::function<bool(Cell)>;
  Test operator!(Test test);
}