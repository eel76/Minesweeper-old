#include "to_string.h"
#include <map>
#include <numeric>

using namespace std::string_literals;

auto minesweeper::to_string(Severity severity) -> std::string {
  return { ".12345678XXXXXXXXX"[severity.m_level] };
}

auto minesweeper::to_string(Threat threat) -> std::string {
  auto severity = to_string(std::get<Severity>(threat));
  return std::map<State, std::string>{ { State::Concealed, "#"s },
                                       { State::Marked, "%"s },
                                       { State::Revealed, severity } }[std::get<State>(threat)];
}

auto minesweeper::to_string(Cells cells) -> std::string {
  return accumulate(begin(cells), end(cells), ""s, [](auto text, auto cell) {
    return text + to_string(std::get<Threat>(cell));
  });
}

auto minesweeper::to_string(Position position) -> std::string {
  return std::to_string(index(std::get<Row>(position))) + ", "s +
         std::to_string(index(std::get<Column>(position)));
}
