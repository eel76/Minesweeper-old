#include "group.h"

using namespace minesweeper;
using namespace std;

map<Row, Positions> minesweeper::groupRows(Positions positions)
{
  auto rows = map<Row, Positions>{};

  for (auto position : positions)
    rows[get<Row>(position)].push_back(position);

  return rows;
}