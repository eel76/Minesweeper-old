#include "uncover.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::toggleFlag(Board board, Position position)
{
  board[position] = toggleFlag(board[position]);
  return board;
}

Board minesweeper::uncover(Board board, Positions positions)
{
  positions = coveredCells(withinBounds(positions, board), board);

  for (auto position : positions)
    board[position] = uncover(board[position]);

  for (auto safeCell : safeCells(positions, board))
    board = uncover(board, neighbors(safeCell));

  return board;
}