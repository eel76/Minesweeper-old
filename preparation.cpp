#include "preparation.h"
#include "neighbors.h"
#include "positions.h"
#include "rectangles.h"
#include <algorithm>
#include <functional>

using namespace std;
using namespace minesweeper;

Board minesweeper::MakeBoard(Size size)
{
  auto board = Board{};

  auto rectangles =
  Rectangles{ Rectangle{ { 0, 0 }, { get<RowCount>(size), get<ColumnCount>(size) } } };
  while (MoveNonEmptyToFront(begin(rectangles), end(rectangles)))
  {
    board[get<0>(rectangles[0])] = {};
    rectangles[2]                = WithoutFirstRow(rectangles[0]);
    rectangles[0]                = FirstRowWithoutFirstColumn(rectangles[0]);
  }

  return board;
}

Board minesweeper::LayMines(Board board, MineCount mineCount)
{
  auto const adjust_mine_count = [&](auto const& position, auto value) {
    get<Mines>(board.at(position)) += value;
  };

  for (auto const& position : RandomPositions(AllPositions(board), mineCount))
  {
    auto const neighbors = Neighbors(board, position);
    for_each(begin(neighbors), end(neighbors),
             bind(adjust_mine_count, placeholders::_1, +1));
    adjust_mine_count(position, -9);
  }

  return board;
}
