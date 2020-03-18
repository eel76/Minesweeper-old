#include "cells.h"

auto minesweeper::cellsOf(Board board) -> Cells {
  auto cells = Cells{};
  cells.reserve(size (board));

  for (auto [position, threat] : board)
    cells.emplace_back(Cell{position, threat});

  return cells;
}
