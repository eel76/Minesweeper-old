#include "game.h"

using namespace minesweeper;

int main()
{
  PlayGame({ 10_columns, 10_rows }, 10_mines);
  return 0;
}
