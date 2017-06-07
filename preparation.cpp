#include "preparation.h"
#include "neighbors.h"
#include "positions.h"
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

Board minesweeper::layMines(Board board, MineCount mineCount)
{
  auto adjust_mine_count = [&](auto position, auto value) {
    get<Mines>(board.at(position)) += value;
  };

  for (auto position : randomPositions(allPositions(board), mineCount))
  {
    auto neighbors = neighborPositions(board, position);
    for_each(begin(neighbors), end(neighbors),
             bind(adjust_mine_count, placeholders::_1, +1));
    adjust_mine_count(position, -9);
  }

  return board;
}
