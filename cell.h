#pragma once
#include "state.h"
#include "threat.h"
#include <string>
#include <utility>

namespace minesweeper
{
  using Cell = std::pair<State, ThreatLevel>;
  Cell        toggleMark(Cell cell);
  Cell        reveal(Cell cell);
  Cell        threaten(Cell cell, Threat threat);
  std::string toString(Cell cell);
  bool        isRevealed(Cell cell);
  bool        isMarked(Cell cell);
  bool        isDeadly(Cell cell);
}