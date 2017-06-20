#pragma once
#include <vector>

namespace minesweeper
{
  enum RowIndex { InvalidRow = -1 };

  enum RowOffset {
    Current = 0,
    PrevRow = -1,
    NextRow = +1,
  };

  using Row = RowIndex;

  using Rows = std::vector<Row>;
  Row shift(Row row, RowOffset offset);
  Rows rows(unsigned count);
}