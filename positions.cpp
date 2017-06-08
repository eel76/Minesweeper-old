#include "positions.h"
#include <algorithm>
#include <iterator>
#include <random>

using namespace minesweeper;
using namespace std;

Positions minesweeper::allCells(Board board)
{
  auto positions = Positions{};
  transform(begin(board), end(board), back_inserter(positions),
            [](auto cell) { return get<Position const>(cell); });

  return positions;
}

Positions minesweeper::onlyMines(Board board, Positions positions)
{
  return{ begin(positions), remove_if(begin(positions), end(positions),
                            [=](auto position) {
                              return !isMine(board.at(position));
                            }) };
}

Positions minesweeper::shuffle(Positions positions)
{
  shuffle(begin(positions), end(positions), ranlux48{ random_device{}() });
  return positions;
}
