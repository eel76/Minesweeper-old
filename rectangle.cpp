#include "rectangle.h"
#include <utility>

using namespace minesweeper;
using namespace std;

Rectangle minesweeper::withoutFirstRow(Rectangle rectangle)
{
  get<0>(get<0>(rectangle)) += 1;
  return rectangle;
}

Rectangle minesweeper::firstRowWithoutFirstColumn(Rectangle rectangle)
{
  get<0>(get<1>(rectangle)) = get<0>(get<0>(rectangle)) + 1;
  get<1>(get<0>(rectangle)) += 1;
  return rectangle;
}
