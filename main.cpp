#include "game.h"

int main()
{
  using namespace minesweeper;

  PlayGame({ 16_columns, 9_rows }, 20_mines);
  return 0;
}
