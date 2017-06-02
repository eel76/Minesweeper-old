#include "uncover.h"
#include <algorithm>
#include <iterator>
#include "neighbors.h"

using namespace minesweeper;
using namespace std;

namespace
{
  auto SelectCovered(Board const& board)
  {
    auto not_covered = [&](auto position) {
      return get<Uncovered>(board.at(position));
    };

    return [=](auto begin, auto end) {
      return distance(begin, remove_if(begin, end, not_covered));
    };
  }

  Positions Branch(Board const& board, Position const& position)
  {
    if (get<Mines>(board.at(position)) == 0)
      return Neighbors(board, position);

    return {};
  }
}

Board minesweeper::Uncover(Board board, Positions positions)
{
  while (!positions.empty())
  {
    auto neighbors                          = Branch(board, positions.back());
    get<Uncovered>(board[positions.back()]) = true;
    positions.insert(end(positions), begin(neighbors), end(neighbors));
    positions.resize(SelectCovered(board)(begin(positions), end(positions)));
  }

  return board;
}

Board minesweeper::Uncover(Board board, Position position)
{
  if (Contains(board, position))
    return Uncover(board, Positions{ position });

  return board;
}
