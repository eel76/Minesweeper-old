#include "state.h"
#include <map>

using namespace minesweeper;
using namespace std;

template <typename... Args>
auto option(Args... args)
{
  return make_pair(args...);
}

template <typename... Args>
auto mapping(Args... args)
{
  return std::map<State, State>{ args... };
}

State minesweeper::reveal(State state)
{
  return mapping(option(State::Covered, State::Revealed),
                 option(State::Marked, State::Marked),
                 option(State::Revealed, State::Revealed))[state];

  // auto revealed = map<State, State>{ make_pair(State::Covered,
  // State::Revealed),
  //                                    make_pair(State::Marked, State::Marked),
  //                                    make_pair(State::Revealed,
  //                                    State::Revealed) };
  // return revealed[state];
}

State minesweeper::toggleMark(State state)
{
  auto markToggled = map<State, State>{ { State::Covered, State::Marked },
                                        { State::Marked, State::Covered },
                                        { State::Revealed, State::Revealed } };
  return markToggled[state];
}