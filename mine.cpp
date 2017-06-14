#include "mine.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

Cell incrementMines(Cell cell, int increment)
{
  return Cell{ get<State>(cell), get<Mines>(cell) + increment };
}

Board minesweeper::layMine(Board board, Position position)
{
  for (auto neighbor : withinBounds(neighbors(position), board))
    board[neighbor] = incrementMines(board[neighbor], +1);

  board[position] = incrementMines(board[position], -9);
  return board;
}

Board minesweeper::layMines(Board board, Positions positions)
{
  for (auto position : positions)
    board = layMine(board, position);

  return board;
}