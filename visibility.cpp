#include "visibility.h"
#include "action.h"

minesweeper::State minesweeper::reveal(State state) {
  auto action = revealAction();
  return action[state];
}

minesweeper::State minesweeper::mark(State state) {
  auto action = markAction();
  return action[state];
}
