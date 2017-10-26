#include "cells.h"
#include <algorithm>
#include <random>

minesweeper::Cells minesweeper::cells(Board board) {
  return { begin(board), end(board) };
}

minesweeper::Cells minesweeper::shuffle(Cells cells) {
  shuffle(begin(cells), end(cells), std::ranlux48{ std::random_device{}() });
  return cells;
}
