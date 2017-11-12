#include "state.h"
#include "action.h"

auto minesweeper::revealed(State state) -> State {
  auto action = revealAction();
  return action[state];
}

auto minesweeper::marked(State state) -> State {
  auto action = markAction();
  return action[state];
}

auto minesweeper::isRevealed(State state) -> bool {
  return state == State::Revealed;
}

auto minesweeper::isMarked(State state) -> bool {
  return state == State::Marked;
}
