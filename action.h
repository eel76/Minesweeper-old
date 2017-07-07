#pragma once
#include "visibility.h"
#include <map>

namespace minesweeper
{
  using Action = std::map<Visibility, Visibility>;
  Action reveal();
  Action changeGuess();
}