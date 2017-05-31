#include "positions.h"
#include <algorithm>
#include <iterator>
#include <random>

using namespace std;
using namespace minesweeper;

Positions minesweeper::AllPositions(Board const& board)
{
  auto positions = Positions{};
  transform(begin(board), end(board), back_inserter(positions),
            [](auto const& cell) { return get<Position const>(cell); });

  return positions;
}

Positions minesweeper::RandomPositions(Board const& board, unsigned position_count)
{
  auto positions = AllPositions(board);
  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });

  auto const count = min<size_t>(position_count, positions.size());
  return { begin(positions), next(begin(positions), count) };
}
