#include "game.h"

using namespace minesweeper;

int main()
{
  PlayGame({ 16_columns, 9_rows }, 20_mines);
  return 0;
}
