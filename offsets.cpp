#include "offsets.h"
#include "columnoffsets.h"
#include "rowoffsets.h"
#include <algorithm>

using namespace minesweeper;

Offsets minesweeper::neighborOffsets()
{
  return {
    { RowOffset::Previous, ColumnOffset::Previous },
    { RowOffset::Previous, ColumnOffset::Current },
    { RowOffset::Previous, ColumnOffset::Next },
    { RowOffset::Current, ColumnOffset::Previous },
    { RowOffset::Current, ColumnOffset::Next },
    { RowOffset::Next, ColumnOffset::Previous },
    { RowOffset::Next, ColumnOffset::Current },
    { RowOffset::Next, ColumnOffset::Next },
  };
}