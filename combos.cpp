#include "combos.h"

auto minesweeper::combos(Rows rows, Columns columns) -> Positions {
  if (rows.empty())
    return {};

  auto positions = combos({ begin(rows) + 1, end(rows) }, columns);

  for (auto column : columns)
    positions.emplace_back(rows[0], column);

  return positions;
}
