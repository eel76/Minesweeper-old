#pragma once
#include "board.h"
#include <string>

namespace minesweeper {
  // template <class... Args>
  // void print(Args... args) {
  //}
  void print(std::string const& text);
  void print(Board board);
  void printCountdown(Board board);
}
