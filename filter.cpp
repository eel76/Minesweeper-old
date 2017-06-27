#include "filter.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Predicate minesweeper::operator!(Predicate predicate)
{
  return [=](auto position) { return !predicate(position); };
}

Predicate minesweeper::within(Board board)
{
  return [=](auto position) { return board.count(position) != 0; };
}

Predicate minesweeper::deadly(Board board)
{
  return [=](auto position) { return isDeadly(board.at(position)); };
}

Predicate minesweeper::uncovered(Board board)
{
  return [=](auto position) {
    return get<State>(board.at(position)) == State::Uncovered;
  };
}

Predicate minesweeper::covered(Board board)
{
  return
  [=](auto position) { return get<State>(board.at(position)) == State::Covered; };
}

Predicate minesweeper::marked(Board board)
{
  return
  [=](auto position) { return get<State>(board.at(position)) == State::Marked; };
}

Predicate minesweeper::minimumThreat(Board board)
{
  return [=](auto position) {
    return get<ThreatLevel>(board.at(position)) == ThreatLevel::Minimum;
  };
}

Positions minesweeper::operator|(Positions positions, Predicate predicate)
{
  positions.erase(remove_if(begin(positions), end(positions),
                            [=](auto position) { return !predicate(position); }),
                  end(positions));
  return positions;
}