#include "player/choose.h"

#include "ask.h"
#include "player/computer.h"
#include "player/human.h"

using namespace std::string_literals;

auto minesweeper::player::choose() -> Player {
  using Players = std::map<std::string, Player>;
  auto players  = Players{ { "h"s, human() }, { "c"s, computer() } };
  auto player   = Player{};

  while (!player)
    player = players[askString("Player: (h)uman or (c)omputer? "s)];

  return player;
}
