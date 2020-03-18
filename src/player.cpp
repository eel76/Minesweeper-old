#include "player.h"

#include "ask.h"
#include "player/computer.h"
#include "player/human.h"

using namespace std::string_literals;

auto minesweeper::choosePlayer() -> Player {
  auto players = std::map<std::string, Player>{ { "h"s, player::human() },
                                                { "c"s, player::computer() } };
  auto player  = Player{};

  while (!player)
    player = players[askString("Player: (h)uman or (c)omputer? "s)];

  return player;
}
