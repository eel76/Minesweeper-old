#include "cell.h"

using namespace minesweeper;
using namespace std;

std::string minesweeper::toString(Cell cell)
{
  char constexpr toChar[2][19] = { "##################", ".12345678XXXXXXXXX" };
  return string{ toChar[get<State>(cell)][get<Threat>(cell)] };
}

Cell minesweeper::uncover(Cell cell)
{
  return Cell{ State::Uncovered, get<Threat>(cell) };
}

Cell minesweeper::threaten(Cell cell, Threat threat)
{
  return Cell{ get<State>(cell), Threat(get<Threat>(cell) + threat) };
}

bool minesweeper::isUncovered(Cell cell)
{
  return get<State>(cell) == State::Uncovered;
}

bool minesweeper::containsMine(Cell cell)
{
  return get<Threat>(cell) >= Threat::SubjacentMine;
}