#include "position.h"

using namespace minesweeper;
using namespace std;

Position minesweeper::shift(Position position, Offset offset)
{
  return Position{ shift(get<Row>(position), get<RowOffset>(offset)),
                   shift(get<Column>(position), get<ColumnOffset>(offset)) };
}