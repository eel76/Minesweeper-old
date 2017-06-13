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

Positions minesweeper::safeCells(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return get<Mines>(board.at(position)) != 0;
           }) };
}