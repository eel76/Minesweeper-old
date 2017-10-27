#include "to_string.h"
#include <map>
#include <numeric>

using namespace std::string_literals;

std::string minesweeper::to_string(Severity severity) {
  return { ".12345678XXXXXXXXX"[severity.m_level] };
}

std::string minesweeper::to_string(Threat threat) {
  auto severity = to_string(std::get<Severity>(threat));
  return std::map<State, std::string>{ { State::Concealed, "#"s },
                                       { State::Marked, "%"s },
                                       { State::Revealed, severity } }[std::get<State>(threat)];
}

std::string minesweeper::to_string(Cells cells) {
  return accumulate(begin(cells), end(cells), ""s, [](auto s, auto cell) {
    return s + to_string(std::get<Threat>(cell));
  });
}
