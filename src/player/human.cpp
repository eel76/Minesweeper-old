#include "player/human.h"
#include "ask.h"
#include "parse.h"

using namespace std::string_literals;

auto minesweeper::player::human() -> Player {
  return [](auto) {
    return parseMove(askString("Your move: [(m)ark] <row> <column>: "s));
  };
}
