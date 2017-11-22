#pragma once
#include "position.h"
#include <set>

namespace minesweeper {
  using Deadly   = std::set<Position>;
  using Severity = std::pair<Deadly, Position>;

  inline Severity mined(Severity severity, Position position) {
    auto deadly = std::get<Deadly>(severity);
    deadly.emplace(position);
    return { deadly, std::get<Position>(severity) };
  }
  inline bool isDeadly(Severity severity) {
    return std::get<Deadly>(severity).count(std::get<Position>(severity)) != 0;
  }
  inline bool isNegligible(Severity severity) {
    return std::get<Deadly>(severity).empty();
  }
}
