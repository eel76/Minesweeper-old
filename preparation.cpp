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

Board minesweeper::makeBoard(Size size)
{
  return initialize(Board{},
                    Rectangle{ { 0, 0 }, { get<RowCount>(size), get<ColumnCount>(size) } });
}

Board layMine(Board board, Position position)
{
  auto adjustMineCount = [&](auto position, auto value) {
    get<Mines>(board.at(position)) += value;
  };

  auto neighbors = neighborPositions(board, position);
  for_each(begin(neighbors), end(neighbors), bind(adjustMineCount, placeholders::_1, +1));
  adjustMineCount(position, -9);
  return board;
}

Board minesweeper::layMines(Board board, MineCount mineCount)
{
  auto positions = shuffle(allPositions(board));
  auto count     = min<size_t>({ mineCount, positions.size() });

  for (auto position : Positions{ begin(positions), next(begin(positions), count) })
    board = layMine(board, position);

  return board;
}
