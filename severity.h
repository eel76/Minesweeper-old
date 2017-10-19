#pragma once
#include "hazard.h"
#include <string>

namespace minesweeper
{
  struct AdjacentMines
  {
    int count;
  };
  inline int count(AdjacentMines adjacentMines)
  {
    return adjacentMines.count;
  }
  inline AdjacentMines increment(AdjacentMines adjacentMines)
  {
    return { count(adjacentMines) + 1 };
  }

  struct Severity
  {
    int level;
  };
  inline bool isDeadly(Severity severity)
  {
    return severity.level >= 9;
  }
  inline bool isNegligible(Severity severity)
  {
    return severity.level == 0;
  }
  std::string to_string(Severity severity);
  Severity    consider(Severity severity, Hazard hazard);
}