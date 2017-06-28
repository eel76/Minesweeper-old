#pragma once

namespace minesweeper
{
  enum struct State { Covered, Marked, Revealed };
  State reveal(State state);
  State toggleMark(State state);
}