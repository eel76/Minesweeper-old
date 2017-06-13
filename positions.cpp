#include "positions.h"
#include <algorithm>
#include <random>

using namespace minesweeper;
using namespace std;

Positions minesweeper::zipWith(Rows rows, int column)
{
  auto positions = Positions{};

  for (auto row : rows)
    positions.push_back(Position{ row, column });

  return positions;
}

Positions minesweeper::join(std::vector<Positions> positionRanges)
{
  auto joined = Positions{};

  for (auto positions : positionRanges)
    joined.insert(end(joined), begin(positions), end(positions));

  return joined;
}

Positions minesweeper::cartesianProduct(Rows rows, Columns columns)
{
  auto positionRanges = std::vector<Positions>{};

  for (auto column : columns)
    positionRanges.push_back(zipWith(rows, column));

  return join(positionRanges);
}

Positions minesweeper::sample(Positions positions, size_t count)
{
  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });
  return { begin(positions), next(begin(positions), min({ positions.size(), count })) };
}