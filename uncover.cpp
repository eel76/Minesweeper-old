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

  for (auto position : safeCells(positions, board))
    board = uncover(board, neighbors(position));

  return board;
}

Cell minesweeper::uncover(Cell cell)
{
  return Cell{ true, get<Mines>(cell) };
}