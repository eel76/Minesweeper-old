#pragma once
#include <string>
#include "board.h"

namespace minesweeper
{
  Position printCell(Board board, Position position);
  Position printRow(Board board, Position position);
  void print(Board board);
  void print(std::string s);
}
