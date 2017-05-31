#include "positions.h"
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;
using namespace minesweeper;

Positions minesweeper::RandomPositions(Board const& board, unsigned position_count)
{
  Positions positions{ board.size() };
  transform(begin(board), end(board), begin(positions),
            [](auto const& cell) { return get<Position const>(cell); });

  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });

  auto const count = min<size_t>(position_count, positions.size());
  return { begin(positions), next(begin(positions), count) };
}
