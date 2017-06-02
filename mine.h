#pragma once

namespace minesweeper
{
  enum MineCount : unsigned
  {
  };
  MineCount operator""_mines(unsigned long long mineCount);
}
