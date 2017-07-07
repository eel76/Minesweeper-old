#include "threat.h"
#include <functional>
#include <map>

using namespace minesweeper;
using namespace std;

template <class T>
using Stringify = std::map<T, std::function<std::string()>>;

std::string minesweeper::toString(Threat threat)
{
  return Stringify<Visibility>{ { Visibility::Concealed, [] { return "#"s; } },
                                { Visibility::Recognized, [] { return "*"s; } },
                                { Visibility::Revealed, [=] {
                                   return Stringify<Severity>{
                                     { Severity::Negligible, [] { return "0"s; } },
                                     { Severity::Deadly, [] { return "X"s; } }
                                   }[get<Severity>(threat)]();
                                 } } }[get<Visibility>(threat)]();
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
  return get<Severity>(threat) >= Severity::Deadly;
}