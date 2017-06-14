#include "mine.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::layMine(Board board, Position position)
{
  for (auto neighbor : withinBounds(neighbors(position), board))
    board[neighbor] = layMines(board[neighbor], MineCount::NeighborMine);

  board[position] = layMines(board[position], MineCount::Mine);
  return board;
}

Board minesweeper::layMines(Board board, Positions positions)
{
  for (auto position : positions)
    board = layMine(board, position);

  return board;
}