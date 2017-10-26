#include "severity.h"
#include <map>

std::string minesweeper::to_string(Severity severity) {
  return { ".12345678XXXXXXXXX"[severity.m_level] };
}

minesweeper::Severity minesweeper::consider(Severity severity, Hazard hazard) {
  return { severity.m_level + int(hazard) };
}
