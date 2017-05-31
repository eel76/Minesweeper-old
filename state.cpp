#include "state.h"

using namespace std;
using namespace minesweeper;

bool minesweeper::IsMine(State const& state)
{
  return get<MineCount>(state) < 0;
}
