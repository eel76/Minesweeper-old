#pragma once

namespace minesweeper
{
  using Row = signed;
  enum RowCount : unsigned
  {
  };
  RowCount operator""_rows(unsigned long long rowCount);
}
