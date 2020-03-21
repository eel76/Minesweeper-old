#include "move/parse.h"

#include "move/mark.h"
#include "move/reveal.h"
#include "io/print.h"

#include <functional>
#include <map>
#include <regex>
#include <string_view>

using namespace std::string_literals;

namespace minesweeper::move { namespace {
  auto invalid(std::string text) -> Move {
    return [=](auto board) {
      io::print("'"s + text + "' is not a valid move. Please try again.\n");
      return board;
    };
  }

  auto match(std::string_view text, std::string_view pattern) {
    auto match = std::cmatch{};
    regex_match(&*begin(text), &*end(text), match,
                std::regex{ begin(pattern), end(pattern) });

    return match;
  }
}}

auto minesweeper::move::parse(std::string text) -> Move {
  auto const match =
  move::match(text, "^ *(m?) *([1-9]*[0-9]) *[,; ] *([1-9]*[0-9]) *$");
  if (match.empty())
    return invalid(text);

  auto const position =
  Position{ Row{ std::stoi(match[2]) }, Column{ std::stoi(match[3]) } };

  using Moves = std::map<std::string, Move>;
  auto moves = Moves{ { ""s, move::reveal(position) }, { "m"s, move::mark(position) } };
  return moves[match[1]];
}
