#include "positions.h"
#include <algorithm>
#include <random>

minesweeper::Positions minesweeper::shuffle(Positions positions)
{
  shuffle(begin(positions), end(positions), std::ranlux48{ std::random_device{}() });
  return positions;
}

minesweeper::Positions minesweeper::first(size_t count, Positions positions)
{
  return { begin(positions), next(begin(positions), std::min({ size(positions), count })) };
}