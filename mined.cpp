#include "mined.h"

#include "cells.h"
#include "concealed.h"
#include "deadly.h"
#include "neighbor.h"
#include "take.h"

auto minesweeper::mined(Board board, Cell cell) -> Board {
  for (auto neighbor : cells(board) | neighborOf(cell))
    board[position(neighbor)] = mined(threat(neighbor), Hazard::Nearby);

  board[position(cell)] = mined(board[position(cell)], Hazard::Deadly);
  return board;
}

auto minesweeper::mined(Board board, unsigned count) -> Board {
  auto const concealedCells = concealed(cells(board));

  for (auto cell : shuffle(concealedCells | !isDeadly()) | take(count))
    board = mined(board, cell);

  return board;
}
