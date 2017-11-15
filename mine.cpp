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

auto minesweeper::minesLayed(Board board, Cells cells) -> Board {
  for (auto cell : cells)
    board = mineLayed(board, std::get<Position>(cell));

  return board;
}

auto minesweeper::minesLayed(Board board, unsigned count) -> Board {
  auto const possibleCells = cells(board) | !isDeadly() | isConcealed();
  return minesLayed(board, shuffled(possibleCells) | take(count));
}
