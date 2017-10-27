#pragma once
#include "visibility.h"
#include <map>

namespace minesweeper {
  using Action = std::map<State, State>;
  Action revealAction();
  Action markAction();
}
