#include "cell.h"
#include <functional>
#include <map>

using namespace minesweeper;
using namespace std;

std::string minesweeper::toString(Cell cell)
{
  auto threatToString = map<State, function<string(ThreatLevel)>>{
    { State::Covered, [](auto) { return string{ "#" }; } },
    { State::Marked, [](auto) { return string{ "*" }; } },
    { State::Uncovered, [](auto threatLevel) { return toString(threatLevel); } }
  };

  return threatToString[get<State>(cell)](get<ThreatLevel>(cell));
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

bool minesweeper::containsMine(Cell cell)
{
  return get<ThreatLevel>(cell) >= ThreatLevel::Mine;
}