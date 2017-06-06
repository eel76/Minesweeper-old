#pragma once
#include "board.h"

namespace minesweeper
{
  bool RoundPossible(Board board);
  Board PlayRound(Board board);
  void EvaluationRound(Board board);
}
