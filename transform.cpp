#include "transform.h"

std::vector<std::string> minesweeper::toStrings(Cells cells)
{
  auto strings = std::vector<std::string>{ cells.size() };

  for (auto cell : cells)
    strings.push_back(to_string(get<Threat>(cell)));

  return strings;
}