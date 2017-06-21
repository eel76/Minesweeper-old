#include "threat.h"

using namespace minesweeper;
using namespace std;

string minesweeper::toString(Threat threat)
{
  return { ".12345678XXXXXXXXX"[threat] };
}