#pragma once

namespace minesweeper
{
  enum State : unsigned { Covered, Marked, Uncovered };
  State uncover(State state);
  State toggleMark(State state);
}