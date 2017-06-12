#include "group.h"

using namespace minesweeper;
using namespace std;

map<int, Positions> minesweeper::groupRows(Positions positions)
{
  auto rows = map<int, Positions>{};

  for (auto position : positions)
    rows[get<0>(position)].push_back(position);

  return rows;
}
