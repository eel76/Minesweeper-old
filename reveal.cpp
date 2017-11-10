#include "reveal.h"
#include "cells.h"
#include "concealed.h"
#include "negligible.h"
#include "neighbor.h"
#include "oneof.h"

using namespace minesweeper;

Board minesweeper::marked(Board board, Positions positions) {
  for (auto cell : cells(board) | oneOf(positions))
    board[std::get<Position>(cell)] = markAction(std::get<Threat>(cell));

  return board;
}

Board minesweeper::revealed(Board board, Positions positions) {
  auto concealedCells = cells(board) | concealed() | oneOf(positions);

  for (auto cell : concealedCells)
    board[std::get<Position>(cell)] = revealAction(std::get<Threat>(cell));

  for (auto cell : concealedCells | isNegligible())
    board =
    revealed(board, toPositions(cells(board) | neighborOf(std::get<Position>(cell))));

  return board;
}
