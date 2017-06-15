#include "parse.h"
#include <regex>

using namespace minesweeper;
using namespace std;

Move minesweeper::parseMove(std::string input)
{
  auto match = smatch{};

  if (regex_match(input, match, regex{ " *([1-9]*[0-9]) *, *([1-9]*[0-9]) *" }))
    return Move{ Action::Uncover, { Row(stoi(match[1])), Column(stoi(match[2])) } };

  return Move{ Action::Uncover, { Row::Invalid, Column::Invalid } };
}