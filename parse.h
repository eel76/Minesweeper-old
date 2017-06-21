#pragma once
#include "move.h"
#include <string>

namespace minesweeper
{
  Position parsePosition(std::string text);
  Move parseMove(std::string text);
}