#include "filter.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::withinBounds(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return !contains(board, position);
           }) };
}

Positions minesweeper::coveredCells(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return get<Uncovered>(board.at(position));
           }) };
}

Positions minesweeper::withoutMines(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return get<Mines>(board.at(position)) != 0;
           }) };
}

Positions minesweeper::onlyMines(Board board, Positions positions)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return !isMine(board.at(position));
           }) };
}

Positions minesweeper::first(size_t count, Positions positions)
{
  return { begin(positions), next(begin(positions), min({ positions.size(), count })) };
}
