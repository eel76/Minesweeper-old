#pragma once

namespace minesweeper
{
  enum State : unsigned { Covered, Flagged, Uncovered };
  State uncover(State state);
  State toggleFlag(State state);
}