#pragma once

namespace minesweeper {
  enum struct State { Concealed, Marked, Revealed };
  State reveal(State state);
  State mark(State state);
  bool  isRevealed(State state);
}
