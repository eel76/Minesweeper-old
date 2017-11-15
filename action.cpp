#include "action.h"

auto minesweeper::revealAction() -> Action {
  return { { State::Concealed, State::Revealed },
           { State::Marked, State::Marked },
           { State::Revealed, State::Revealed } };
}

auto minesweeper::markAction() -> Action {
  return { { State::Concealed, State::Marked },
           { State::Marked, State::Concealed },
           { State::Revealed, State::Revealed } };
}
