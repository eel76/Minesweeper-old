#pragma once
#include <string>
#include "hazard.h"

namespace minesweeper
{
  enum struct Severity { Negligible = Hazard::None, Deadly = Hazard::Mine };
  std::string toString(Severity severity);
  Severity consider(Severity severity, Hazard hazard);
}