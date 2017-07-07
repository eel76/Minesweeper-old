#include "position.h"
#include <algorithm>

int minesweeper::maximumDistance(Position first, Position second)
{
  auto rowDistance = distance(std::get<Row>(first), std::get<Row>(second));
  auto columnDistance = distance(std::get<Column>(first), std::get<Column>(second));

  return std::max(rowDistance, columnDistance);
}