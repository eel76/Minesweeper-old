#include "uncover.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::uncover(Board board, Positions positions)
{
  positions = coveredCells(withinBounds(positions, board), board);

  for (auto position : positions)
    board[position] = uncover(board[position]);

  for (auto position : clearCells(positions, board))
    board = uncover(board, neighbors(position));

  return board;
}