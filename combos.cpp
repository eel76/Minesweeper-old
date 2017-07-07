#include "combos.h"
#include "join.h"

minesweeper::Positions minesweeper::allCombos(Rows rows, Column column)
{
  auto positions = Positions{};

  for (auto row : rows)
    // positions.push_back(Position{ row, column });
    positions = join({ positions, { Position{ row, column } } });

  return positions;
}

minesweeper::Positions minesweeper::allCombos(Rows rows, Columns columns)
{
  auto positions = Positions{};

  for (auto column : columns)
    positions = join({ positions, allCombos(rows, column) });

  return positions;
}