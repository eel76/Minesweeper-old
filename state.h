#pragma once

namespace minesweeper
{
  enum State { Covered, Marked, Revealed };
  State reveal(State state);
  State toggleMark(State state);
}