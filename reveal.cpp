#include "reveal.h"
#include "cells.h"
#include "concealed.h"
#include "negligible.h"
#include "neighbor.h"
#include "oneof.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::changeMark(Board board, Positions positions) {
  for (auto cell : cells(board) | oneOf(positions))
    board[get<Position>(cell)] = changeMark(get<Threat>(cell));

  return board;
}

Board minesweeper::reveal(Board board, Positions positions) {
  auto concealedCells = cells(board) | concealed() | oneOf(positions);

  for (auto cell : concealedCells)
    board[get<Position>(cell)] = reveal(get<Threat>(cell));

  for (auto cell : concealedCells | isNegligible())
    board = reveal(board, toPositions(cells(board) | neighborOf(get<Position>(cell))));

  return board;
}
