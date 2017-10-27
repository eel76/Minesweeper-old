#include "threat.h"

using namespace minesweeper;
using namespace std;

Threat minesweeper::markAction(Threat threat) {
  return Threat{ mark(get<State>(threat)), get<Severity>(threat) };
}

Threat minesweeper::revealAction(Threat threat) {
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

bool minesweeper::deadly(Threat threat) {
  return deadly(get<Severity>(threat));
}
