#include "transform.h"
#include <string>

std::vector<std::string> minesweeper::toString(Cells cells) {
  auto strings = std::vector<std::string>{ cells.size() };

  for (auto cell : cells)
    strings.push_back(to_string(std::get<Threat>(cell)));

  return strings;
}
