#include "cell.h"
#include <functional>
#include <map>

using namespace minesweeper;
using namespace std;

std::string toString(Threat threat)
{
  return { ".12345678XXXXXXXXX"[threat] };
}

std::string minesweeper::toString(Cell cell)
{
  auto threatToString = map<State, function<string(Threat)>>{
    { State::Covered, [](auto) { return string{ "#" }; } },
    { State::Marked, [](auto) { return string{ "*" }; } },
    { State::Uncovered, [](auto threat) { return ::toString(threat); } }
  };

  return threatToString[get<State>(cell)](get<Threat>(cell));
}

Cell minesweeper::toggleMark(Cell cell)
{
  return Cell{ toggleMark(get<State>(cell)), get<Threat>(cell) };
}

Cell minesweeper::uncover(Cell cell)
{
  return Cell{ uncover(get<State>(cell)), get<Threat>(cell) };
}

Cell minesweeper::threaten(Cell cell, Threat threat)
{
  return Cell{ get<State>(cell), Threat(get<Threat>(cell) + threat) };
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
  return get<Threat>(cell) >= Threat::Mine;
}