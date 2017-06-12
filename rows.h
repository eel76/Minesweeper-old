#pragma once

namespace minesweeper
{
  enum RowCount : unsigned {};
  RowCount operator""_rows(unsigned long long rowCount);
}
