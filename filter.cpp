#include "filter.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::allCells(Board board)
{
  auto positions = Positions{ board.size() };
  transform(begin(board), end(board), begin(positions),
            [](auto cell) { return get<Position const>(cell); });

  return positions;
}

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
