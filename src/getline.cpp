#include "getline.h"
#include <iostream>

auto minesweeper::getline() -> std::string {
  auto line = std::string{};
  getline(std::cin, line);

  return line;
}
