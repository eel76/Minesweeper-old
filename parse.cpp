#include "parse.h"
#include <regex>

using namespace minesweeper;
using namespace std;

Position minesweeper::parsePosition(std::string input)
{
  auto match = smatch{};

  if (regex_match(input, match, regex{ " *([1-9]*[0-9]) *, *([1-9]*[0-9]) *" }))
    return Position{ stoi(match[1]), stoi(match[2]) };

  return Position{ -1, -1 };
}