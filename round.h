#pragma once
#include "board.h"

namespace minesweeper
{
  bool IsRoundPossible(Board board);
  Board PlayRound(Board board);
  void EndRound(Board board);
}
