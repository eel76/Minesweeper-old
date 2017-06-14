#include "mine.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::layMine(Board board, Position position)
{
  for (auto neighbor : withinBounds(neighbors(position), board))
    board[neighbor] = threaten(board[neighbor], Threat::AdjacentMine);

  board[position] = threaten(board[position], Threat::SubjacentMine);
  return board;
}

Board minesweeper::layMines(Board board, Positions positions)
{
  for (auto position : positions)
    board = layMine(board, position);

  return board;
}