#include "state.h"
#include <map>

using namespace minesweeper;
using namespace std;

State minesweeper::reveal(State state)
{
  auto revealed = map<State, State>{ { State::Covered, State::Revealed },
                                     { State::Marked, State::Marked },
                                     { State::Revealed, State::Revealed } };
  return revealed[state];
}

State minesweeper::toggleMark(State state)
{
  auto markToggled = map<State, State>{ { State::Covered, State::Marked },
                                        { State::Marked, State::Covered },
                                        { State::Revealed, State::Revealed } };
  return markToggled[state];
}