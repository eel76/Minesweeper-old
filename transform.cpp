#include "transform.h"
#include <numeric>

using namespace std::string_literals;

std::string minesweeper::to_string(Cells cells) {
  return accumulate(begin(cells), end(cells), ""s, [](auto s, auto cell) {
    return s + to_string(std::get<Threat>(cell));
  });
}
