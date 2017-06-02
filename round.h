#pragma once
#include "board.h"

namespace minesweeper
{
  bool NextRoundPossible(Board board);
  Board NextRound(Board board);
  void EvaluationRound(Board board);
}
