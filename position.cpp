#include "position.h"

using namespace minesweeper;
using namespace std;

Position minesweeper::shift(Position first, std::pair<int, int> steps)
{
  return { shift(get<Row>(first), get<0>(steps)),
           shift(get<Column>(first), get<1>(steps)) };
}