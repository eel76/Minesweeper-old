#include "move.h"
#include <regex>
#include "input.h"

using namespace std;
using namespace minesweeper;

Move minesweeper::PlayerMove()
{
  smatch match;

  string const line = InputLine();
  if (regex_match(line, match, regex{ " *([1-9]*[0-9]) *, *([1-9]*[0-9]) *" }))
    return { true, { stoi(match[1]), stoi(match[2]) } };

  return { false, {} };
}
