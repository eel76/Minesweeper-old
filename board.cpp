#include "board.h"

using namespace minesweeper;

bool minesweeper::Contains(Board const& board, Position const& position)
{
  return board.count(position);
}
