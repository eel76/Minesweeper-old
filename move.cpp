#include "move.h"
#include <regex>

using namespace std;
using namespace minesweeper;

Move minesweeper::ParseMove(std::string const& input)
{
  smatch match;
  if (regex_match(input, match, regex{ " *([1-9]*[0-9]) *, *([1-9]*[0-9]) *" }))
    return { true, { stoi(match[1]), stoi(match[2]) } };

  return { false, {} };
}
