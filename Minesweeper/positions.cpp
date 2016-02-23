#include "positions.h"
#include <algorithm>
#include <array>
#include <iterator>
#include <random>

using namespace std;

namespace minesweeper
{
namespace
{
constexpr array<Position, 8> kOffsets
{ {
  { -1, -1 }, { -1,  0 }, { -1, +1 },
  {  0, -1 },             {  0, +1 },
  { +1, -1 }, { +1,  0 }, { +1, +1 }
} };
}

Positions NeighborPositions(Board const& board, Position const& position)
{
  Positions neighbors{ kOffsets.size() };
  transform(begin(kOffsets), end(kOffsets), begin(neighbors), [=](auto const& offset)
  {
    return Add(position, offset);
  });

  auto const on_board = remove_if(begin(neighbors), end(neighbors), [&](auto const& position)
  {
    return !board.count(position);
  });
  return{ begin(neighbors), on_board };
}
Positions RandomPositions(Board const& board, unsigned position_count)
{
  Positions positions{ board.size() };
  transform(begin(board), end(board), begin(positions), [](auto const& cell)
  {
    return get<Position const>(cell);
  });

  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });

  auto const count = min<size_t>(position_count, positions.size());
  return{ begin(positions), next(begin(positions), count) };
}
}
