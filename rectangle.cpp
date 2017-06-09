#include "rectangle.h"

using namespace minesweeper;
using namespace std;

Rectangle minesweeper::makeRectangle(Size size)
{
  return { { 0, 0 }, { get<RowCount>(size), get<ColumnCount>(size) } };
}

bool minesweeper::isEmpty(Rectangle rectangle)
{
  return !(get<0>(rectangle) < get<1>(rectangle));
}
