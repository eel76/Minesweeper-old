#pragma once
#include <string>
#include "position.h"

namespace minesweeper
{
  Position ParsePosition(std::string const& input);
}
