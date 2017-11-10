#pragma once
#include "state.h"
#include <map>

namespace minesweeper {
  using Action = std::map<State, State>;
  Action revealAction();
  Action markAction();
}
