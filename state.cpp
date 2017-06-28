#include "state.h"
#include <map>

using namespace minesweeper;
using namespace std;

State minesweeper::reveal(State state)
{
  return map<State, State>{ { State::Covered, State::Revealed },
                            { State::Marked, State::Covered },
                            { State::Revealed, State::Revealed } }[state];
}

State minesweeper::toggleMark(State state)
{
  return map<State, State>{ { State::Covered, State::Marked },
                            { State::Marked, State::Covered },
                            { State::Revealed, State::Revealed } }[state];
}