#include "mine.h"
#include "cells.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::layMine(Board board, Position position)
{
  for (auto neighbor : cells(board) | neighborOf(position))
    board[get<Position>(neighbor)] = consider(get<Threat>(neighbor), Hazard::AdjacentMine);

  board[position] = consider(board[position], Hazard::Mine);
  return board;
}

Board minesweeper::layMines(Board board, Positions positions)
{
  for (auto position : positions)
    board = layMine(board, position);

  return board;
}