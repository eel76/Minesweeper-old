#include "severity.h"

#include <map>

using namespace minesweeper;
using namespace std;

std::string minesweeper::to_string(Hazards hazards)
{
  return ""s;
}

Hazards minesweeper::consider(Hazards hazards, Hazard hazard)
{
  auto consider = map<Hazard, Hazards>{
    { Hazard::AdjacentMine,
      Hazards{ get<IsMine>(hazards), increment(get<AdjacentMines>(hazards)) } },
    { Hazard::Mine, Hazards{ IsMine::Yes, get<AdjacentMines>(hazards) } },
  };
  return consider[hazard];
}

string minesweeper::to_string(Severity severity)
{
  return { ".12345678XXXXXXXXX"[severity.level] };
}

Severity minesweeper::consider(Severity severity, Hazard hazard)
{
  return { severity.level + int(hazard) };
}