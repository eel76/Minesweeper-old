#include "board.h"

using namespace minesweeper;

bool minesweeper::contains(Board board, Position position)
{
  return board.count(position) != 0;
}
