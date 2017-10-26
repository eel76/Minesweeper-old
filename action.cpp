#include "action.h"

minesweeper::Action minesweeper::reveal() {
  return { { State::Concealed, State::Revealed },
           { State::Marked, State::Marked },
           { State::Revealed, State::Revealed } };
}

minesweeper::Action minesweeper::mark() {
  return { { State::Concealed, State::Marked },
           { State::Marked, State::Concealed },
           { State::Revealed, State::Revealed } };
}
