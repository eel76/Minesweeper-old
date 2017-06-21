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

Positions minesweeper::withMine(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return !containsMine(board.at(position));
           }) };
}

Positions minesweeper::coveredCells(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return isUncovered(board.at(position));
           }) };
}

Positions minesweeper::safeAreas(Positions positions, Board board)
{
  return { begin(positions), remove_if(begin(positions), end(positions), [=](auto position) {
             return get<ThreatLevel>(board.at(position)) != ThreatLevel::Minimum;
           }) };
}