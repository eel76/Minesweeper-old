#pragma once
#include <string>

namespace minesweeper
{
  enum struct Row { Invalid = -1 };
  int index(Row row);
  int distance(Row first, Row second);
  std::string to_string(Row row);
}