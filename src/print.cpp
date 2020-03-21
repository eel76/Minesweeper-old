#include "print.h"

#include <iostream>

using namespace std::string_literals;

void minesweeper::print(std::string const& text) {
  std::cout << text;
}

void minesweeper::printIf(std::string const& text, bool condition) {
  if (condition)
    print(text);
}
