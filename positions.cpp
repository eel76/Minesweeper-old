#include "positions.h"
#include <algorithm>
#include <random>

using namespace minesweeper;
using namespace std;

Positions minesweeper::add(Positions positions, Position offset)
{
  return { begin(positions),
           transform(begin(positions), end(positions), begin(positions),
                     [=](auto position) { return position + offset; }) };
}

Positions minesweeper::shuffle(Positions positions)
{
  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });
  return positions;
}
