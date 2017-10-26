#include "transform.h"
#include <algorithm>

std::vector<std::string> minesweeper::toString(Cells cells) {
  auto strings = std::vector<std::string>{ cells.size() };
  transform(begin(cells), end(cells), begin(strings),
            [](auto cell) { return to_string(std::get<Threat>(cell)); });

  return strings;
}
