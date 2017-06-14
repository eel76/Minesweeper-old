#include "filter.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

Positions minesweeper::withinBounds(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return board.count(position) == 0;
           }) };
}

Positions minesweeper::coveredCells(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return get<State>(board.at(position)) == State::Uncovered;
           }) };
}

Positions minesweeper::clearCells(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return get<MineCount>(board.at(position)) != 0;
           }) };
}