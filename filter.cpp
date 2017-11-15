#include "filter.h"
#include <algorithm>

auto minesweeper::operator!(Filter test) -> Filter {
  return [=](auto cell) { return !test(cell); };
}

auto minesweeper::operator|(Cells cells, Filter test) -> Cells {
  cells.erase(std::remove_if(begin(cells), end(cells), !test), end(cells));
  return cells;
}
