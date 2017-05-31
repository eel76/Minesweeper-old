#include "board.h"
#include "rectangles.h"

using namespace std;
using namespace minesweeper;

Board minesweeper::CreateBoard(unsigned height, unsigned width)
{
  auto board = Board{};

  auto rectangles = Rectangles{ Rectangle{ { 0, 0 }, { height, width } } };
  while (MoveNonEmptyToFront(begin(rectangles), end(rectangles)))
  {
    board[get<0>(rectangles[0])] = {};
    rectangles[2] = WithoutFirstRow(rectangles[0]);
    rectangles[0] = FirstRowWithoutFirstColumn(rectangles[0]);
  }

  return board;
}

bool minesweeper::Contains(Board const& board, Position const& position)
{
  return board.count(position);
}
