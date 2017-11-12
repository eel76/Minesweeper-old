#include "preparation.h"
#include "combos.h"

auto minesweeper::setupBoard(Rows rows, Columns columns) -> Board {
  auto board = Board{};

  for (auto position : combos(rows, columns))
    board[position] = Threat{};

  return board;
}
