#include "action.h"

minesweeper::Action minesweeper::revealAction() {
  return { { State::Concealed, State::Revealed },
           { State::Marked, State::Marked },
           { State::Revealed, State::Revealed } };
}

minesweeper::Action minesweeper::markAction() {
  return { { State::Concealed, State::Marked },
           { State::Marked, State::Concealed },
           { State::Revealed, State::Revealed } };
}
