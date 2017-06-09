#include "preparation.h"
#include "filter.h"
#include "neighbors.h"
#include "rectangle.h"
#include <algorithm>
#include <functional>

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

Board resetRegion(Board board, Rectangle rectangle)
{
  if (isEmpty(rectangle))
    return board;

  board.insert({ get<0>(rectangle), {} });
  board = resetRegion(board, withoutFirstRow(rectangle));
  board = resetRegion(board, firstRowWithoutFirstColumn(rectangle));

  return board;
}

Board layMine(Board board, Position position)
{
  for (auto neighbor : onlyInside(board, add(neighbors(), position)))
    get<Mines>(board.at(neighbor)) += 1;

  get<Mines>(board.at(position)) -= 9;
  return board;
}

Board minesweeper::prepareBoard(Size size, MineCount mineCount)
{
  auto board = resetRegion(Board{}, makeRectangle(size));

  for (auto position : onlyFirst(mineCount, shuffle(allCells(board))))
    board = layMine(board, position);

  return board;
}
