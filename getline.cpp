#include "getline.h"
#include <iostream>

std::string minesweeper::getline() {
  auto line = std::string{};
  getline(std::cin, line);

  return line;
}
