#include "severity.h"

minesweeper::Severity minesweeper::consider(Severity severity, Hazard hazard) {
  return { severity.m_level + int(hazard) };
}
