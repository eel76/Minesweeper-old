#include "transform.h"
#include <numeric>

std::string minesweeper::to_string(Cells cells) {
  using namespace std::string_literals;
  return accumulate(begin(cells), end(cells), ""s, [](auto s, auto cell) {
    return s + to_string(std::get<Threat>(cell));
  });
}
