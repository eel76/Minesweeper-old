#include "position.h"

#include <algorithm>

auto minesweeper::row(Position position) -> Row {
  return std::get<Row> (position);
}

auto minesweeper::column(Position position) -> Column {
  return std::get<Column> (position);
}

auto minesweeper::maximumDistance(Position first, Position second) -> int {
  auto const rowDistance = distance(row(first), row(second));
  auto const columnDistance = distance(column(first), column(second));

  return std::max(rowDistance, columnDistance);
}
