#include "parse.h"
#include <functional>
#include <map>
#include <regex>

using namespace minesweeper;
using namespace std;

template <class Value>
using Generator = std::function<Value()>;

Position minesweeper::parsePosition(std::string text)
{
  auto match = smatch{};
  regex_match(text, match, regex{ "^ *([1-9]*[0-9]) *[,; ] *([1-9]*[0-9]) *$" });

  auto positions = map<bool, Generator<Position>>{
    { false,
      [=] {
        return Position{ Row(stoi(match[1])), Column(stoi(match[2])) };
      } },
    { true,
      [] {
        return Position{ Row::Invalid, Column::Invalid };
      } }
  };

  return positions[match.empty()]();
}

Move minesweeper::parseMove(std::string text)
{
  auto match = smatch{};
  regex_match(text, match, regex{ "^ *(m?|mark)(.+)$" });

  auto action = map<string, Action>{ { "", Action::Uncover },
                                     { "m", Action::ToggleMark },
                                     { "mark", Action::ToggleMark } };
  return Move{ action[match[1]], parsePosition(match[2]) };
}