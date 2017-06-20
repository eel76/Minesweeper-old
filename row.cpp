#include "row.h"

using namespace minesweeper;

Row minesweeper::shift(Row row, RowOffset offset)
{
  return Row(int(row) + int(offset));
}