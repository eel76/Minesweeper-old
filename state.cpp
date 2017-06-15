#include "state.h"
#include <map>

using namespace minesweeper;
using namespace std;

State minesweeper::uncover(State state)
{
  auto uncovered = map<State, State>{ { State::Covered, State::Uncovered },
                                      { State::Flagged, State::Flagged },
                                      { State::Uncovered, State::Uncovered } };
  return uncovered[state];
}

State toggleFlag(State state)
{
  auto toggledFlag = map<State, State>{ { State::Covered, State::Flagged },
                                        { State::Flagged, State::Covered },
                                        { State::Uncovered, State::Uncovered } };
  return toggledFlag[state];
}