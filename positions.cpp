#include "positions.h"
#include "join.h"
#include <algorithm>
#include <random>

using namespace minesweeper;
using namespace std;

Positions minesweeper::allCombos(Rows rows, Column column)
{
  auto positions = Positions{};

  for (auto row : rows)
    positions.push_back(Position{ row, column });

  return positions;
}

Positions minesweeper::allCombos(Rows rows, Columns columns)
{
  auto positions = Positions{};

  for (auto column : columns)
    positions = join({ positions, allCombos(rows, column) });

  return positions;
}

Positions minesweeper::sample(Positions positions, size_t count)
{
  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });
  return { begin(positions), next(begin(positions), min({ size(positions), count })) };
}