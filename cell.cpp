#include "cell.h"

using namespace minesweeper;
using namespace std;

std::string minesweeper::toString(Cell cell)
{
  char constexpr toChar[2][19] = { "##################", ".12345678XXXXXXXXX" };
  return string{ toChar[get<State>(cell)][get<MineCount>(cell)] };
}

Cell minesweeper::uncover(Cell cell)
{
  return Cell{ State::Uncovered, get<MineCount>(cell) };
}

Cell minesweeper::incrementMines(Cell cell, int increment)
{
  return Cell{ get<State>(cell), get<MineCount>(cell) + increment };
}

bool minesweeper::isUncovered(Cell cell)
{
  return get<State>(cell) == State::Uncovered;
}

bool minesweeper::containsMine(Cell cell)
{
  return get<MineCount>(cell) > 8;
}