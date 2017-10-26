#include "visibility.h"
#include "action.h"

minesweeper::State minesweeper::reveal(State state) {
  auto action = reveal();
  return action[state];
}

minesweeper::State minesweeper::changeMark(State state) {
  auto action = changeMark();
  return action[state];
}
