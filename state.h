#pragma once

namespace minesweeper {
  enum struct State { Concealed, Marked, Revealed };
  State revealed(State state);
  State marked(State state);
  bool  isRevealed(State state);
  bool  isMarked(State state);
}
