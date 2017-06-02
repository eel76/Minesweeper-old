#include "board.h"

using namespace minesweeper;

bool minesweeper::Contains(Board board, Position position)
{
  return board.count(position);
}
