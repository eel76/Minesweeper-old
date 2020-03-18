#include "parse.h"
#include <functional>
#include <map>
#include <regex>

// FIXME: use unknownMove()

using namespace std::string_literals;

auto minesweeper::parsePosition(std::string text) -> Position {
  auto match = std::smatch{};
  regex_match(text, match, std::regex{ "^ *([1-9]*[0-9]) *[,; ] *([1-9]*[0-9]) *$" });

  auto positions = std::map<bool, std::function<Position()>>{
    { false,
      [=] {
        return Position{ Row(std::stoi(match[1])), Column(std::stoi(match[2])) };
      } },
    { true,
      [] {
        return Position{ Row::Invalid, Column::Invalid };
      } }
  };

  return positions[match.empty()]();
}

auto minesweeper::parseMove(std::string text) -> Move {
  auto match = std::smatch{};
  regex_match(text, match, std::regex{ "^ *(m?)(.+)$" });

  auto parse =
  std::map<std::string, Move>{ { ""s, revealingMove(parsePosition(match[2])) },
                               { "m"s, markingMove(parsePosition(match[2])) } };
  return parse[match[1]];
}
