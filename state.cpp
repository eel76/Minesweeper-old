#include "state.h"

using namespace std;
using namespace minesweeper;

string minesweeper::ToString(State const& state)
{
  char constexpr kStateChar[2][19] = { "##################",
                                       "XXXXXXXXX.12345678" };

  return { kStateChar[get<Uncovered>(state)][get<MineCount>(state) + 9] };
}
