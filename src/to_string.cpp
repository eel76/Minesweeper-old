#include "to_string.h"

#include <map>
#include <numeric>

using namespace std::string_literals;

auto minesweeper::to_string(Mines mines) -> std::string {
  return ""s + ".12345678XXXXXXXX"[mines[Hazard::Nearby] + 9 * mines[Hazard::Deadly]];
}

auto minesweeper::to_string(Threat threat) -> std::string {
  return std::map<State, std::string>{ { State::Concealed, "#"s },
                                       { State::Marked, "*"s },
                                       { State::Revealed,
                                         to_string(mines(threat)) } }[state(threat)];
}

auto minesweeper::to_string(Cells cells) -> std::string {
  return accumulate(begin(cells), end(cells), ""s, [](auto text, auto cell) {
    return text + to_string(threat(cell));
  });
}

auto minesweeper::to_string(Position position) -> std::string {
  return std::to_string(index(row(position))) + ", "s +
         std::to_string(index(column(position)));
}
