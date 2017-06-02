#include "mine.h"

using namespace std;
using namespace minesweeper;

MineCount minesweeper::operator""_mines(unsigned long long mineCount)
{
  return static_cast<MineCount>(mineCount);
}
