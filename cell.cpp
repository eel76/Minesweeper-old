#include "cell.h"
#include <map>

using namespace minesweeper;
using namespace std;

std::string minesweeper::toString(Cell cell)
{
  auto strings =
  map<State, string>{ { State::Covered, "#"s },
                      { State::Marked, "*"s },
                      { State::Uncovered, toString(get<ThreatLevel>(cell)) } };
  return strings[get<State>(cell)];
}

Cell minesweeper::toggleMark(Cell cell)
{
  return Cell{ toggleMark(get<State>(cell)), get<ThreatLevel>(cell) };
}

Cell minesweeper::uncover(Cell cell)
{
  return Cell{ uncover(get<State>(cell)), get<ThreatLevel>(cell) };
}

Cell minesweeper::threaten(Cell cell, Threat threat)
{
  return Cell{ get<State>(cell), increase(get<ThreatLevel>(cell), threat) };
}

bool minesweeper::isUncovered(Cell cell)
{
  return get<State>(cell) == State::Uncovered;
}

bool minesweeper::isMarked(Cell cell)
{
  return get<State>(cell) == State::Marked;
}

bool minesweeper::isDeadly(Cell cell)
{
  return get<ThreatLevel>(cell) >= ThreatLevel::Deadly;
}