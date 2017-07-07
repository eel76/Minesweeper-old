#include "positions.h"
#include <algorithm>

minesweeper::Positions minesweeper::first(size_t count, Positions positions)
{
  return { begin(positions), next(begin(positions), std::min({ size(positions), count })) };
}