#include "visibility.h"
#include "action.h"

minesweeper::State minesweeper::reveal(State visibility) {
  auto action = reveal();
  return action[visibility];
}

minesweeper::State minesweeper::changeMark(State visibility) {
  auto action = changeMark();
  return action[visibility];
}
