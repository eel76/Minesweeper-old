#include "visibility.h"
#include "action.h"

minesweeper::State minesweeper::reveal(State state) {
  auto action = reveal();
  return action[state];
}

minesweeper::State minesweeper::mark(State state) {
  auto action = mark();
  return action[state];
}
