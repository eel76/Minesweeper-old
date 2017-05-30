#include "rectangle.h"

using namespace std;
using namespace minesweeper;

Rectangle minesweeper::WithoutFirstRow (Rectangle rectangle)
{
  get<0> (get<0> (rectangle)) += 1;
  return rectangle;
}
Rectangle minesweeper::FirstRowWithoutFirstColumn (Rectangle rectangle)
{
  get<0> (get<1> (rectangle)) = get<0> (get<0> (rectangle)) + 1;
  get<1> (get<0> (rectangle)) += 1;
  return rectangle;
}
