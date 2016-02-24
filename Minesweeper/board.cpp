#include "board.h"
#include <algorithm>
#include <array>

using namespace std;
using namespace minesweeper;

namespace
{
using Rectangle = pair<Position, Position>;
using Rectangles = array<Rectangle, 3>;

Rectangle WithoutFirstRow(Rectangle rectangle)
{
  get<0>(get<0>(rectangle)) += 1;
  return rectangle;
}
Rectangle FirstRowWithoutFirstColumn(Rectangle rectangle)
{
  get<0>(get<1>(rectangle)) = get<0>(get<0>(rectangle)) + 1;
  get<1>(get<0>(rectangle)) += 1;
  return rectangle;
}
bool MoveNonEmptyToFront(Rectangles::iterator begin, Rectangles::iterator end)
{
  return begin != partition(begin, end, [](auto const& rectangle)
  {
    return StrictlyLess(get<0>(rectangle), get<1>(rectangle));
  });
}
}

Board minesweeper::CreateBoard(unsigned height, unsigned width)
{
  Board board;

  Rectangles rectangles{ Rectangle{ { 0, 0 }, { height, width } } };
  while (MoveNonEmptyToFront(begin(rectangles), end(rectangles)))
  {
    board[get<0>(rectangles[0])] = {};
    rectangles[2] = WithoutFirstRow(rectangles[0]);
    rectangles[0] = FirstRowWithoutFirstColumn(rectangles[0]);
  }

  return board;
}
