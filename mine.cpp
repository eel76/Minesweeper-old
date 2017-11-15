#include "mine.h"
#include "cells.h"
#include "concealed.h"
#include "deadly.h"
#include "neighbor.h"
#include "take.h"

auto minesweeper::mineLayed(Board board, Position position) -> Board {
  for (auto neighbor : cells(board) | neighborOf(position))
    board[std::get<Position>(neighbor)] =
    considered(std::get<Threat>(neighbor), Hazard::AdjacentMine);

  board[position] = considered(board[position], Hazard::Mine);
  return board;
}

auto minesweeper::minesLayed(Board board, unsigned count) -> Board {
  auto const possibleMines = cells(board) | isConcealed() | !isDeadly();

  for (auto mine : shuffled(possibleMines) | take(count))
    board = mineLayed(board, std::get<Position>(mine));

  return board;
}
