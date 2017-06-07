#include "board.h"

bool minesweeper::contains(Board board, Position position)
{
  return board.count(position) != 0;
}
