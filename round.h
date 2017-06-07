#pragma once
#include "board.h"

namespace minesweeper
{
  Board playRound(Board board);
  bool roundPossible(Board board);
  void evaluationRound(Board board);
}
