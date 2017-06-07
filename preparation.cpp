#include "preparation.h"
#include "neighbor.h"
#include "rectangles.h"
#include <algorithm>
#include <functional>

using namespace minesweeper;
using namespace std;

Board minesweeper::makeBoard(Size size)
{
  auto board = Board{};

  auto rectangles =
  Rectangles{ Rectangle{ { 0, 0 }, { get<RowCount>(size), get<ColumnCount>(size) } } };
  while (moveNonEmptyToFront(begin(rectangles), end(rectangles)))
  {
    board.insert({ get<0>(rectangles[0]), {} });
    rectangles[2] = withoutFirstRow(rectangles[0]);
    rectangles[0] = firstRowWithoutFirstColumn(rectangles[0]);
  }

  return board;
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
