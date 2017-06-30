#include "severity.h"

using namespace minesweeper;
using namespace std;

string minesweeper::toString(Severity severity)
{
  return { ".12345678XXXXXXXXX"[int(severity)] };
}

Severity minesweeper::consider(Severity severity, Hazard hazard)
{
  return Severity(int(severity) + int(hazard));
}