#include "severity.h"

#include <map>

using namespace minesweeper;
using namespace std;

string minesweeper::to_string(Severity severity)
{
  return { ".12345678XXXXXXXXX"[severity.level] };
}

Severity minesweeper::consider(Severity severity, Hazard hazard)
{
  return { severity.level + int(hazard) };
}