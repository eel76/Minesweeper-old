#include "severity.h"

bool minesweeper::isDeadly(Severity severity) {
  return severity.m_level >= 9;
}

bool minesweeper::isNegligible(Severity severity) {
  return severity.m_level == 0;
}

minesweeper::Severity minesweeper::considered(Severity severity, Hazard hazard) {
  return { severity.m_level + int(hazard) };
}
