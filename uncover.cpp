#include "uncover.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

bool minesweeper::isCovered(Board board, Position position)
{
  return !get<Uncovered>(board[position]);
}

Board minesweeper::uncover(Board board, Position position)
{
  if (!contains(board, position) || !isCovered(board, position))
    return board;

  get<Uncovered>(board[position]) = true;
  if (get<Mines>(board.at(position)) != 0)
    return board;

  return uncover(board, add(neighbors(), position));
}

Board minesweeper::uncover(Board board, Positions positions)
{
  for (auto position : positions)
    board = uncover(board, position);

  return board;
}
