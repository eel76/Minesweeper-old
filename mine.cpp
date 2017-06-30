#include "mine.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::layMine(Board board, Position position)
{
  for (auto neighbor : neighbors(position) | within(board))
    board[neighbor] = consider(board[neighbor], Hazard::AdjacentMine);

  board[position] = consider(board[position], Hazard::Mine);
  return board;
}

Board minesweeper::layMines(Board board, Positions positions)
{
  for (auto position : positions)
    board = layMine(board, position);

  return board;
}