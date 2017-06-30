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

Predicate minesweeper::revealed(Board board)
{
  return [=](auto position) {
    return get<Visibility>(board.at(position)) == Visibility::Revealed;
  };
}

Predicate minesweeper::covered(Board board)
{
  return
  [=](auto position) { return get<Visibility>(board.at(position)) == Visibility::Concealed; };
}

Predicate minesweeper::marked(Board board)
{
  return
  [=](auto position) { return get<Visibility>(board.at(position)) == Visibility::Recognized; };
}

Predicate minesweeper::minimalThreat(Board board)
{
  return [=](auto position) {
    return get<Severity>(board.at(position)) == Severity::Negligible;
  };
}

Positions minesweeper::operator|(Positions positions, Predicate predicate)
{
  positions.erase(remove_if(begin(positions), end(positions),
                            [=](auto position) { return !predicate(position); }),
                  end(positions));
  return positions;
}