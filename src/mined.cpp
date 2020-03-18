#include "mined.h"

#include "cells.h"
#include "concealed.h"
#include "deadly.h"
#include "neighbor.h"
#include "take.h"

#include <algorithm>
#include <random>

auto minesweeper::mined(Board board, Cell cell) -> Board {
  for (auto neighbor : cellsOf(board) | neighborOf(cell))
    board[position(neighbor)] = mined(threat(neighbor), Hazard::Nearby);

  board[position(cell)] = mined(board[position(cell)], Hazard::Deadly);
  return board;
}

auto minesweeper::mined(Board board, unsigned count) -> Board {
  auto cells = concealed(cellsOf(board)) | !isDeadly();
  shuffle(begin(cells), end(cells), std::ranlux48{ std::random_device{}() });

  for (auto cell : cells | take(count))
    board = mined(board, cell);

  return board;
}
