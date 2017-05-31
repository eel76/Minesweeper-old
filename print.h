#pragma once
#include <string>
#include "board.h"

namespace minesweeper
{
  void Print(Board const& board);
  void Print(State const& state);
  void Print(std::string const& str);
}
