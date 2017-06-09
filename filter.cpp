#include "filter.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::onlyInside(Board board, Positions positions)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return !contains(board, position);
           }) };
}

Positions minesweeper::onlyMines(Board board, Positions positions)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return !isMine(board.at(position));
           }) };
}

Positions minesweeper::onlyFirst(size_t count, Positions positions)
{
  return { begin(positions), next(begin(positions), min({ positions.size(), count })) };
}
