#include "group.h"

auto minesweeper::byRow(Cells cells) -> std::map<Row, Cells> {
  auto rows = std::map<Row, Cells>{};

  for (auto cell : cells)
    rows[row(position(cell))].push_back(cell);

  return rows;
}
