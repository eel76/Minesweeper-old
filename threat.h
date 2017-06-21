#pragma once
#include <string>

namespace minesweeper
{
  enum struct Threat { None = 0, AdjacentMine = 1, Mine = 9 };
  enum struct ThreatLevel { Minimum = Threat::None, Deadly = Threat::Mine };
  std::string toString(ThreatLevel threatLevel);
  ThreatLevel increase(ThreatLevel threatLevel, Threat threat);
}