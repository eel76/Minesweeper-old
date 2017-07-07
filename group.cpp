#include "group.h"

std::map<minesweeper::Row, minesweeper::Positions> minesweeper::byRow(Positions positions)
{
  auto rows = std::map<Row, Positions>{};

  for (auto position : positions)
    rows[std::get<Row>(position)].push_back(position);

  return rows;
}