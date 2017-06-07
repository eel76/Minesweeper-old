#include "uncover.h"
#include "neighbor.h"

using namespace minesweeper;
using namespace std;

bool isCovered(Board board, Position position)
{
  return !get<Uncovered>(board[position]);
}

Board minesweeper::uncoverCell(Board board, Position position)
{
  if (!contains(board, position) || !isCovered(board, position))
    return board;

  get<Uncovered>(board[position]) = true;
  if (get<Mines>(board.at(position)) != 0)
    return board;

  return uncoverCells(board, neighborPositions(board, position));
}

Board minesweeper::uncoverCells(Board board, Positions positions)
{
  for (auto position : positions)
    board = uncoverCell(board, position);

  return board;
}

Board minesweeper::uncoverMines(Board board)
{
  for (auto& cell : board)
    get<Uncovered>(get<State>(cell)) |= isMine(get<State>(cell));

  return board;
}
