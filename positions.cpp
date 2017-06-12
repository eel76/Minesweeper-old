#include "positions.h"
#include <algorithm>
#include <random>

using namespace minesweeper;
using namespace std;

Positions minesweeper::shuffle(Positions positions)
{
  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });
  return positions;
}
