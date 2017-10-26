#include "mine.h"
#include "cells.h"
#include "concealed.h"
#include "neighbor.h"
#include "take.h"

minesweeper::Board minesweeper::layMine(Board board, Position position) {
  for (auto neighbor : cells(board) | neighborOf(position))
    board[std::get<Position>(neighbor)] =
    consider(std::get<Threat>(neighbor), Hazard::AdjacentMine);

  board[position] = consider(board[position], Hazard::Mine);
  return board;
}

minesweeper::Board minesweeper::layMines(Board board, Positions positions) {
  for (auto position : positions)
    board = layMine(board, position);

  return board;
}

minesweeper::Board minesweeper::layMines(Board board, unsigned count) {
  auto const concealedCells = cells(board) | concealed();
  return layMines(board, toPositions(shuffle(concealedCells) | take(count)));
}
