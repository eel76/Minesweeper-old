#include "preparation.h"
#include "cells.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

State incrementMines(State state, int increment)
{
  return State{ get<Uncovered>(state), get<Mines>(state) + increment };
}

Board layMine(Board board, Position position)
{
  for (auto neighbor : withinBounds(neighbors(position), board))
    board[neighbor] = incrementMines(board[neighbor], +1);

  board[position] = incrementMines(board[position], -9);
  return board;
}

Board minesweeper::prepareBoard(Size size, MineCount mineCount)
{
  auto board = Board{};

  for (auto position : cartesianProduct(get<0>(size), get<1>(size)))
    board[position] = {};

  for (auto position : sample(allCells(board), mineCount))
    board = layMine(board, position);

  return board;
}