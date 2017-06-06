#include "positions.h"
#include <algorithm>
#include <iterator>
#include <random>

using namespace minesweeper;
using namespace std;

Positions minesweeper::allPositions(Board board)
{
  auto positions = Positions{};
  transform(begin(board), end(board), back_inserter(positions),
            [](auto cell) { return get<Position const>(cell); });

  return positions;
}

Positions minesweeper::randomPositions(Positions positions, unsigned position_count)
{
  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });

  auto count = min<size_t>(position_count, positions.size());
  return { begin(positions), next(begin(positions), count) };
}
