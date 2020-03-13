#include "reveal.h"
#include "cells.h"
#include "concealed.h"
#include "negligible.h"
#include "neighbor.h"

auto minesweeper::marked(Board board, Cells cells) -> Board {
  for (auto cell : cells)
    board[position(cell)] = marked(threat(cell));

  return board;
}

auto minesweeper::revealed(Board board, Cells cs) -> Board {
  for (auto cell : cs | isConcealed())
    board[position(cell)] = revealed(threat(cell));

  for (auto cell : cs | isConcealed() | isNegligible())
    board = revealed(board, cells(board) | neighborOf(position(cell)));

  return board;
}
