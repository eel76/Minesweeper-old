#pragma once

namespace minesweeper
{
  enum ColumnCount : unsigned {};
  ColumnCount operator""_columns(unsigned long long columnCount);
}
