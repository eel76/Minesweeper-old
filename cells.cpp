#include "cells.h"

#include <algorithm>
#include <random>

auto minesweeper::cells(Board board) -> Cells {
  auto cells = Cells{};
  cells.reserve(size (board));

  for (auto [position, threat] : board)
    cells.emplace_back(Cell{position, threat});

  return cells;
}

auto minesweeper::shuffle(Cells cells) -> Cells {
  shuffle(begin(cells), end(cells), std::ranlux48{ std::random_device{}() });
  return cells;
}
