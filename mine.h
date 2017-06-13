#pragma once

namespace minesweeper
{
  enum MineCount : size_t {};
  MineCount operator""_mines(unsigned long long mineCount);
}