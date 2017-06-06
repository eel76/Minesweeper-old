#pragma once
#include "board.h"

namespace minesweeper
{
  bool roundPossible(Board board);
  Board playRound(Board board);
  void evaluationRound(Board board);
}
