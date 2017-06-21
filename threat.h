#pragma once
#include <string>

namespace minesweeper
{
  enum struct Threat { AdjacentMine = 1, Mine = 9 };
  enum struct ThreatLevel { Minimum = 0, Mine = Threat::Mine };
  std::string toString(ThreatLevel threatLevel);
  ThreatLevel increase(ThreatLevel threatLevel, Threat threat);
}