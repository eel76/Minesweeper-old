#include "positions.h"
#include <algorithm>
#include <random>

using namespace minesweeper;
using namespace std;

Positions minesweeper::sample(Positions positions, size_t count)
{
  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });
  return { begin(positions), next(begin(positions), min({ positions.size(), count })) };
}
