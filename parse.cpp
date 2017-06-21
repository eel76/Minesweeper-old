#include "parse.h"
#include <map>
#include <regex>

using namespace minesweeper;
using namespace std;

Position minesweeper::parsePosition(std::string text)
{
  auto match = smatch{};
  regex_match(text, match, regex{ " *([1-9]*[0-9]) *[,; ] *([1-9]*[0-9]) *" });

  auto positions =
  map<size_t, Position>{ { 0, Position{ Row::Invalid, Column::Invalid } },
                         { 3, Position{ Row(stoi("0"s + match[1])),
                                        Column(stoi(match[2])) } } };
  return positions[match.size()];
}

Move minesweeper::parseMove(std::string text)
{
  auto match = smatch{};
  regex_match(text, match, regex{ " *(m?|mark) *(.+)" });

  auto actions = map<string, Action>{ { "", Action::Uncover },
                                      { "m", Action::ToggleMark },
                                      { "mark", Action::ToggleMark } };
  return Move{ actions[match[1]], parsePosition(match[2]) };
}