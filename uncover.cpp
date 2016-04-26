#include "uncover.h"
#include "positions.h"
#include <algorithm>
#include <iterator>

using namespace std;
using namespace minesweeper;

namespace
{
auto SelectCovered(Board const& board)
{
  auto const not_covered = [&](auto const& position)
  {
    return get<Uncovered>(board.at(position));
  };

  return [=](auto begin, auto end)
  {
    return distance(begin, remove_if(begin, end, not_covered));
  };
}
Positions Branch(Board const& board, Position const& position)
{
  if (get<MineCount>(board.at(position)) == 0)
    return NeighborPositions(board, position);

  return{};
}
}

Board minesweeper::Uncover(Board board, Position const& starting_position)
{
  Positions positions{ starting_position };
  while (!positions.empty())
  {
    auto const neighbors = Branch(board, positions.back());
    get<Uncovered>(board[positions.back()]) = true;
    positions.insert(end(positions), begin(neighbors), end(neighbors));
    positions.resize(SelectCovered(board)(begin(positions), end(positions)));
  }

  return board;
}
