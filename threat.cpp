#include "threat.h"
#include <cassert>

using namespace minesweeper;
using namespace std;

string minesweeper::toString(ThreatLevel threatLevel)
{
  return { ".12345678XXXXXXXXX"[int(threatLevel)] };
}

ThreatLevel minesweeper::increase(ThreatLevel threatLevel, Threat threat)
{
  return ThreatLevel(int(threatLevel) + int(threat));
}