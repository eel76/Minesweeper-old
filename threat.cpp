#include "threat.h"
#include <functional>
#include <map>

using namespace minesweeper;
using namespace std;

std::string minesweeper::to_string(Threat threat) {
  auto severity = to_string(get<Severity>(threat));
  return map<State, string>{ { State::Concealed, "#"s },
                             { State::Marked, "%"s },
                             { State::Revealed, severity } }[get<State>(threat)];
}

Threat minesweeper::mark(Threat threat) {
  return Threat{ mark(get<State>(threat)), get<Severity>(threat) };
}

Threat minesweeper::reveal(Threat threat) {
  return Threat{ reveal(get<State>(threat)), get<Severity>(threat) };
}

Threat minesweeper::consider(Threat threat, Hazard hazard) {
  return Threat{ get<State>(threat), consider(get<Severity>(threat), hazard) };
}

bool minesweeper::isRevealed(Threat threat) {
  return get<State>(threat) == State::Revealed;
}

bool minesweeper::isRecognized(Threat threat) {
  return get<State>(threat) == State::Marked;
}

bool minesweeper::isDeadly(Threat threat) {
  return isDeadly(get<Severity>(threat));
}
