#include "position.h"
#include <algorithm>

auto minesweeper::maximumDistance(Position first, Position second) -> int {
  auto const rowDistance = distance(std::get<Row>(first), std::get<Row>(second));
  auto const columnDistance = distance(std::get<Column>(first), std::get<Column>(second));

  return std::max(rowDistance, columnDistance);
}
