#include "state.h"
#include <map>

using namespace minesweeper;
using namespace std;

State minesweeper::uncover(State state)
{
  auto uncovered = map<State, State>{ { State::Covered, State::Uncovered },
                                      { State::Marked, State::Marked },
                                      { State::Uncovered, State::Uncovered } };
  return uncovered[state];
}

State minesweeper::toggleMark(State state)
{
  auto toggledFlag = map<State, State>{ { State::Covered, State::Marked },
                                        { State::Marked, State::Covered },
                                        { State::Uncovered, State::Uncovered } };
  return toggledFlag[state];
}