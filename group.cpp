#include "group.h"

auto minesweeper::byRow(Cells cells) -> std::map<Row, Cells> {
  auto rows = std::map<Row, Cells>{};

  for (auto cell : cells)
    rows[std::get<Row>(std::get<Position>(cell))].push_back(cell);

  return rows;
}
