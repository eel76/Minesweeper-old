#include "severity.h"

auto minesweeper::considered(Severity severity, Hazard hazard) -> Severity {
  return { severity.m_level + static_cast<int>(hazard) };
}

auto minesweeper::isDeadly(Severity severity) -> bool {
  return severity.m_level >= 9;
}

auto minesweeper::isNegligible(Severity severity) -> bool {
  return severity.m_level == 0;
}
