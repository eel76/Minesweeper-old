#include "uncover.h"
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

Board minesweeper::uncover(Board board, Position position)
{
  if (!contains(board, position) || get<Uncovered>(board[position]))
    return board;

  get<Uncovered>(board[position]) = true;
  if (get<Mines>(board[position]) != 0)
    return board;

  return uncover(board, add(neighbors(), position));
}

Board minesweeper::uncover(Board board, Positions positions)
{
  for (auto position : positions)
    board = uncover(board, position);

  return board;
}

// board = board | uncover(positions);

// Board uncover(Board board, Positions positions)
// {
//   positions = positions | Inside {board} | covered(board);

//   for (auto position : positions)
//     get<Uncovered>(board[position]) = true;

//   return uncover (board, positions | zeroMines(board) | neighbors());
// }
