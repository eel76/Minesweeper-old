#pragma once
#include "hazard.h"
#include <string>


namespace minesweeper
{
  enum struct Severity { Negligible = Hazard::None, Deadly = Hazard::Mine };
  std::string to_string(Severity severity);
  Severity consider(Severity severity, Hazard hazard);
}