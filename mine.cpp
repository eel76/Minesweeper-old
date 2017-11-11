#include "mine.h"
#include "cells.h"
#include "concealed.h"
#include "deadly.h"
#include "neighbor.h"
#include "take.h"

minesweeper::Board minesweeper::mineLayed(Board board, Position position) {
  for (auto neighbor : cells(board) | neighborOf(position))
    board[std::get<Position>(neighbor)] =
    considered(std::get<Threat>(neighbor), Hazard::AdjacentMine);

  board[position] = considered(board[position], Hazard::Mine);
  return board;
}

minesweeper::Board minesweeper::minesLayed(Board board, Positions positions) {
  for (auto position : positions)
    board = mineLayed(board, position);

  return board;
}

minesweeper::Board minesweeper::minesLayed(Board board, unsigned count) {
  auto const concealedCells = cells(board) | !isDeadly() | isConcealed();
  return minesLayed(board, toPositions(shuffled(concealedCells) | take(count)));
}
