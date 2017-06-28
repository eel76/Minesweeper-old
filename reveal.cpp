#include "reveal.h"
#include "filter.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::toggleMark(Board board, Positions positions)
{
  for (auto position : positions | within(board))
    board[position] = toggleMark(board[position]);

  return board;
}

Board minesweeper::reveal(Board board, Positions positions)
{
  positions = positions | within(board) | covered(board);

  for (auto position : positions)
    board[position] = reveal(board[position]);

  for (auto safeArea : positions | minimumThreat(board))
    board = reveal(board, neighbors(safeArea));

  return board;
}