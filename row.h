#pragma once

namespace minesweeper {
  enum struct Row { Invalid = -1 };
  int index(Row row);
  int distance(Row first, Row second);
}
