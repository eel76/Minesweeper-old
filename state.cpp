#include "state.h"
#include <utility>

using namespace std;

bool minesweeper::isMine(State state)
{
  return get<Mines>(state) < 0;
}