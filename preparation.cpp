#include "preparation.h"
#include "cells.h"
#include "filter.h"
#include "neighbors.h"
#include "rectangle.h"

using namespace minesweeper;
using namespace std;

Rectangle withoutFirstRow(Rectangle rectangle)
{
  get<0>(get<0>(rectangle)) += 1;
  return rectangle;
}

Rectangle firstRowWithoutFirstColumn(Rectangle rectangle)
{
  get<0>(get<1>(rectangle)) = get<0>(get<0>(rectangle)) + 1;
  get<1>(get<0>(rectangle)) += 1;
  return rectangle;
}

Board reset(Board board, Positions positions)
{
  for (auto position : positions)
    board[position] = State();

  return board;
}

Board reset(Board board, Rectangle rectangle)
{
  return board;
}

Board resetRegion(Board board, Rectangle rectangle)
{
  if (isEmpty(rectangle))
    return board;

  board[get<0>(rectangle)] = {};
  board                    = resetRegion(board, withoutFirstRow(rectangle));
  board = resetRegion(board, firstRowWithoutFirstColumn(rectangle));

  return board;
}

Board layMine(Board board, Position position)
{
  for (auto neighbor : withinBounds(add(neighbors(), position), board))
    get<Mines>(board[neighbor]) += 1;

  get<Mines>(board[position]) -= 9;
  return board;
}

Board minesweeper::prepareBoard(Size size, MineCount mineCount)
{
  auto board = resetRegion(Board{}, makeRectangle(size));

  for (auto position : first(mineCount, shuffle(allCells(board))))
    board = layMine(board, position);

  return board;
}
