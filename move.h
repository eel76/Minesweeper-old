#pragma once
#include "action.h"
#include "board.h"
#include "position.h"

namespace minesweeper
{
  using Move = std::pair<Action, Position>;
  Move playerMove();
  Move computerMove(Board board);
}