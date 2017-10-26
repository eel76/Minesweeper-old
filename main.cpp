#include "mine.h"
#include "player.h"
#include "preparation.h"
#include <iostream>

using namespace minesweeper;

int main() {
  play(choosePlayer(), layMines(setupBoard(10_rows, 10_columns), 10));
  std::cin.get();
}
