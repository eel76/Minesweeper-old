#include "positions.h"
#include <algorithm>
#include <random>

minesweeper::Positions minesweeper::shuffle(Positions positions)
{
  shuffle(begin(positions), end(positions), std::ranlux48{ std::random_device{}() });
  return positions;
}

minesweeper::Positions minesweeper::sample(Positions positions, size_t count)
{
  positions = shuffle(positions);
  return { begin(positions), next(begin(positions), std::min({ size(positions), count })) };
}