#include "player/human.h"

#include "ask.h"
#include "move/parse.h"

using namespace std::string_literals;

auto minesweeper::player::human() -> Player {
  return [](auto) {
    return move::parse(askString("Your move: [(m)ark] <row> <column>: "s));
  };
}
