#include "column.h"

namespace minesweeper
{
  Column minesweeper::shift(Column column, ColumnOffset offset)
  {
    return Column(int(column) + int(offset));
  }
}