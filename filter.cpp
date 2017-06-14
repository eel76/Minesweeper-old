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
             return isUncovered(board.at(position));
           }) };
}

Positions minesweeper::safeCells(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return get<Threat>(board.at(position)) != Threat::None;
           }) };
}