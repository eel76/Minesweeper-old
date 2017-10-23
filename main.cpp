#include "player.h"
#include "preparation.h"
#include <iostream>

int main()
{
  using namespace minesweeper;

  play(choosePlayer(), makeBoard());
  std::cin.get();
}
