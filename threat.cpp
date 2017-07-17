#include "threat.h"
#include <functional>
#include <map>

using namespace minesweeper;
using namespace std;

std::string minesweeper::to_string(Threat threat)
{
  auto severity = to_string(get<Severity>(threat));
  return map<Visibility, string>{ { Visibility::Concealed, "#"s },
                                  { Visibility::Recognized, "!"s },
                                  { Visibility::Revealed, severity } }[get<Visibility>(threat)];
}

Threat minesweeper::changeGuess(Threat threat)
{
  return Threat{ changeGuess(get<Visibility>(threat)), get<Severity>(threat) };
}

Threat minesweeper::reveal(Threat threat)
{
  return Threat{ reveal(get<Visibility>(threat)), get<Severity>(threat) };
}

Threat minesweeper::consider(Threat threat, Hazard hazard)
{
  return Threat{ get<Visibility>(threat), consider(get<Severity>(threat), hazard) };
}

bool minesweeper::isRevealed(Threat threat)
{
  return get<Visibility>(threat) == Visibility::Revealed;
}

bool minesweeper::isRecognized(Threat threat)
{
  return get<Visibility>(threat) == Visibility::Recognized;
}

bool minesweeper::isDeadly(Threat threat)
{
  return isDeadly(get<Severity>(threat));
}