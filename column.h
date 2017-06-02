#pragma once

namespace minesweeper
{
  using Column = signed;
  enum ColumnCount : unsigned
  {
  };
  ColumnCount operator""_columns(unsigned long long columnCount);
}
