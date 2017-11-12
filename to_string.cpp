#include "to_string.h"
#include <map>
#include <numeric>

using namespace std;
using namespace string_literals;

string minesweeper::to_string(Severity severity) {
  return { ".12345678XXXXXXXXX"[severity.m_level] };
}

string minesweeper::to_string(Threat threat) {
  auto severity = to_string(get<Severity>(threat));
  return map<State, string>{ { State::Concealed, "#"s },
                             { State::Marked, "%"s },
                             { State::Revealed, severity } }[get<State>(threat)];
}

string minesweeper::to_string(Cells cells) {
  return accumulate(begin(cells), end(cells), ""s, [](auto s, auto cell) {
    return s + to_string(get<Threat>(cell));
  });
}

string minesweeper::to_string(Position position) {
  return std::to_string(index(get<Row>(position))) + ", "s +
         std::to_string(index(get<Column>(position)));
}
