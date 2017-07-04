#include "position.h"
#include <algorithm>

int minesweeper::maximumDistance(Position first, Position second)
{
  auto rowDistance =
  std::abs(index(std::get<Row>(first)) - index(std::get<Row>(second)));
  auto columnDistance =
  std::abs(index(std::get<Column>(first)) - index(std::get<Column>(second)));

  return std::max(rowDistance, columnDistance);
}