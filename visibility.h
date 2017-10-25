#pragma once

namespace minesweeper {
  enum struct State { Concealed, Marked, Revealed };
  State reveal(State visibility);
  State changeMark(State visibility);
}
