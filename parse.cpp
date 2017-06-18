#include "parse.h"
#include <map>
#include <regex>

using namespace minesweeper;
using namespace std;

Move minesweeper::parseMove(std::string input)
{
  auto match = smatch{};

  if (!regex_match(input, match, regex{ " *(f?) *([1-9]*[0-9]) *[,; ] *([1-9]*[0-9]) *" }))
    return Move{ Action::Uncover, { Row::Invalid, Column::Invalid } };

  auto action =
  map<string, Action>{ { "", Action::Uncover }, { "f", Action::ToggleFlag } };

  return Move{ action[match[1]], { Row(stoi(match[2])), Column(stoi(match[3])) } };
}