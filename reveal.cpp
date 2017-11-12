#include "reveal.h"
#include "cells.h"
#include "concealed.h"
#include "negligible.h"
#include "neighbor.h"

auto minesweeper::marked(Board board, Cells cells) -> Board {
  for (auto cell : cells)
    board[std::get<Position>(cell)] = marked(std::get<Threat>(cell));

  return board;
}

auto minesweeper::revealed(Board board, Cells cs) -> Board {
  for (auto cell : cs | isConcealed())
    board[std::get<Position>(cell)] = revealed(std::get<Threat>(cell));

  for (auto cell : cs | isConcealed() | isNegligible())
    board = revealed(board, cells(board) | neighborOf(std::get<Position>(cell)));

  return board;
}
