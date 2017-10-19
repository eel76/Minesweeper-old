#pragma once
#include "board.h"
#include <string>

namespace minesweeper
{
  void print(std::string const& text);
  void print(Board board);
  void printCountdown(Board board);
}