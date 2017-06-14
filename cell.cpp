#include "cell.h"

using namespace minesweeper;
using namespace std;

std::string minesweeper::toString(Cell cell)
{
  char constexpr toChar[2][19] = { "##################", ".12345678XXXXXXXXX" };
  return string{ toChar[get<State>(cell)][get<Mines>(cell)] };
}

Cell minesweeper::incrementMines(Cell cell, int increment)
{
  return Cell{ get<State>(cell), get<Mines>(cell) + increment };
}

bool minesweeper::isMine(Cell cell)
{
  return get<Mines>(cell) > 8;
}