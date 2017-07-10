#pragma once
#include "hazard.h"
#include <string>

namespace minesweeper
{
  // struct AdjacentMines
  // {
  //   int count;
  // };
  // int count(AdjacentMines adjacentMines);

  // enum struct Deadly { No, Yes };
  // using Severity = std::pair<Deadly, AdjacentMines>;

  enum struct Severity { Negligible = Hazard::None, Deadly = Hazard::Mine };
  std::string to_string(Severity severity);
  Severity consider(Severity severity, Hazard hazard);
}