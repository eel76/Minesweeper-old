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

Cell minesweeper::layMines(Cell cell, MineCount mineCount)
{
  return Cell{ get<State>(cell), MineCount(get<MineCount>(cell) + mineCount) };
}

bool minesweeper::isUncovered(Cell cell)
{
  return get<State>(cell) == State::Uncovered;
}

bool minesweeper::containsMine(Cell cell)
{
  return get<MineCount>(cell) >= MineCount::Mine;
}