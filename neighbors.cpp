#include "neighbors.h"
#include <algorithm>

using namespace minesweeper;
using namespace std;

using RowOffsets    = std::vector<RowOffset>;
using ColumnOffsets = std::vector<ColumnOffset>;

RowOffsets rowOffsets()
{
  return { PreviousRow, CurrentRow, NextRow };
}

ColumnOffsets columnOffsets()
{
  return { PreviousColumn, CurrentColumn, NextColumn };
}

using Offset  = std::pair<RowOffset, ColumnOffset>;
using Offsets = std::vector<Offset>;

Offsets cartesianProduct(RowOffsets rowOffsets, ColumnOffsets columnOffsets);
Offsets withoutCenter(Offsets offsets);

Offsets minesweeper::neighborOffsets()
{
  return withoutCenter(cartesianProduct(rowOffsets(), columnOffsets()));
}

Positions minesweeper::neighbors(Position position)
{
  auto neighbors = Positions{};

  for (auto offset : neighborOffsets())
    neighbors.push_back(shift(position, offset));

  return neighbors;
}