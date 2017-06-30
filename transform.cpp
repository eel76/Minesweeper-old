#include "transform.h"

using namespace minesweeper;
using namespace std;

std::vector<std::string> minesweeper::toStrings(Cells cells)
{
  auto strings = std::vector<std::string>{ cells.size() };

  for (auto cell : cells)
    strings.push_back(toString(get<Threat>(cell)));

  return strings;
}