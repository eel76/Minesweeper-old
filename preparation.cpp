#include "preparation.h"
#include "neighbor.h"
#include "rectangle.h"
#include <algorithm>
#include <functional>

using namespace minesweeper;
using namespace std;

bool isEmpty(Rectangle rectangle)
{
  return !(get<0>(rectangle) < get<1>(rectangle));
}

Board initialize(Board board, Rectangle rectangle)
{
  if (isEmpty(rectangle))
    return board;

  board.insert({ get<0>(rectangle), {} });
  board = initialize(board, withoutFirstRow(rectangle));
  board = initialize(board, firstRowWithoutFirstColumn(rectangle));

  return board;
}

Positions selectFirst(Positions positions, size_t count)
{
  return { begin(positions), next(begin(positions), min({ positions.size(), count })) };
}

Board layMine(Board board, Position position)
{
  for (auto neighbor : validNeighbors(board, position))
    get<Mines>(board.at(neighbor)) += 1;

  get<Mines>(board.at(position)) -= 9;
  return board;
}

Board layMines(Board board, MineCount mineCount)
{
  for (auto position : selectFirst(shuffle(allCells(board)), mineCount))
    board = layMine(board, position);

  return board;
}

Board minesweeper::prepareBoard(Size size, MineCount mineCount)
{
  auto board =
  initialize(Board{},
             Rectangle{ { 0, 0 }, { get<RowCount>(size), get<ColumnCount>(size) } });

  return layMines(board, mineCount);
}
