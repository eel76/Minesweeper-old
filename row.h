#pragma once
#include <string>

namespace minesweeper
{
  enum struct Row { Invalid = -1 };
  int         index(Row row);
  std::string to_string(Row row);
}