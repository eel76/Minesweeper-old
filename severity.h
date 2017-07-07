#pragma once
#include "hazard.h"
#include <string>

namespace minesweeper
{
  enum AdjacentMines {};
  enum struct Deadly { No, Yes };
  using Severity = std::pair<Deadly, AdjacentMines>;

  enum struct Severity { Negligible = Hazard::None, Deadly = Hazard::Mine };
  std::string toString(Severity severity);
  Severity    consider(Severity severity, Hazard hazard);
}