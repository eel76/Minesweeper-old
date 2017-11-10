#include "state.h"
#include "action.h"

minesweeper::State minesweeper::revealed(State state) {
  auto action = revealAction();
  return action[state];
}

minesweeper::State minesweeper::marked(State state) {
  auto action = markAction();
  return action[state];
}
