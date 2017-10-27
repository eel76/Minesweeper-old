#include "filter.h"
#include <algorithm>

minesweeper::Filter minesweeper::operator!(Filter test) {
  return [=](auto cell) { return !test(cell); };
}

minesweeper::Cells minesweeper::operator|(Cells cells, Filter test) {
  cells.erase(std::remove_if(begin(cells), end(cells), !test), end(cells));
  return cells;
}
