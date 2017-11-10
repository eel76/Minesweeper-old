#include "cells.h"
#include <algorithm>
#include <random>

auto minesweeper::cells(Board board) -> Cells {
  return { begin(board), end(board) };
}

auto minesweeper::shuffled(Cells cells) -> Cells {
  shuffle(begin(cells), end(cells), std::ranlux48{ std::random_device{}() });
  return cells;
}
