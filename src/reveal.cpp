#include "reveal.h"
#include "cells.h"
#include "concealed.h"
#include "negligible.h"
#include "neighbor.h"

auto minesweeper::toggleMark(Board board, Cells cells) -> Board {
  for (auto cell : cells)
    board[position(cell)] = toggleMark(threat(cell));

  return board;
}

auto minesweeper::reveal(Board board, Cells cells) -> Board {
  auto const concealedCells = concealed(cells);

  for (auto cell : concealedCells)
    board[position(cell)] = reveal(threat(cell));

  for (auto cell : concealedCells | isNegligible())
    board = reveal(board, cellsOf(board) | neighborOf(cell));

  return board;
}
