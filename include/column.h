#pragma once

namespace minesweeper {
  enum struct Column { Invalid = -1 };
  int index(Column column);
  int distance(Column first, Column second);
}
