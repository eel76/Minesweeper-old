#include "cell.h"
#include <utility>

using namespace std;

bool minesweeper::isMine(Cell cell)
{
  return get<Mines>(cell) < 0;
}