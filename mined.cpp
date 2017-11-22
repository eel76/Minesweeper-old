#include "mined.h"
#include "cells.h"
#include "concealed.h"
#include "deadly.h"
#include "neighbor.h"
#include "take.h"

auto minesweeper::mined(Board board, Position position) -> Board {
  for (auto neighbor : cells(board) | neighborOf(position))
    board[std::get<Position>(neighbor)] =
    mined(std::get<Threat>(neighbor), Hazard::NearbyMine);

  board[position] = mined(board[position], Hazard::Mine);
  return board;
}

auto minesweeper::mined(Board board, unsigned count) -> Board {
  auto const concealedCells = cells(board) | isConcealed();

  for (auto cell : shuffled(concealedCells | !isDeadly()) | take(count))
    board = mined(board, std::get<Position>(cell));

  return board;
}
