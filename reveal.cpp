#include "reveal.h"
#include "cells.h"
#include "concealed.h"
#include "negligible.h"
#include "neighbor.h"
#include "oneof.h"

minesweeper::Board minesweeper::marked(Board board, Cells cells) {
  for (auto cell : cells)
    board[std::get<Position>(cell)] = markAction(std::get<Threat>(cell));

  return board;
}

minesweeper::Board minesweeper::revealed(Board board, Cells cs) {
  for (auto cell : cs | isConcealed())
    board[std::get<Position>(cell)] = revealAction(std::get<Threat>(cell));

  for (auto cell : cs | isConcealed() | isNegligible())
    board = revealed(board, cells(board) | neighborOf(std::get<Position>(cell)));

  return board;
}
