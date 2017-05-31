#include "parse.h"
#include <regex>

using namespace std;
using namespace minesweeper;

Position minesweeper::ParsePosition(std::string const& input)
{
  smatch match;
  if (regex_match(input, match, regex{ " *([1-9]*[0-9]) *, *([1-9]*[0-9]) *" }))
    return { stoi(match[1]), stoi(match[2]) };

  return { -1, -1 };
}
