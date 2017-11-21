#include "combos.h"
#include <initializer_list>

namespace {
  template <class Container>
  Container join(std::initializer_list<Container> containerLists) {
    auto joined = Container{};

    for (auto container : containerLists)
      joined.insert(end(joined), begin(container), end(container));

    return joined;
  }
}

auto minesweeper::combos(Rows rows, Column column) -> Positions {
  auto positions = Positions{};

  for (auto row : rows)
    positions = join({ positions, Positions{ Position{ row, column } } });

  return positions;
}

auto minesweeper::combos(Rows rows, Columns columns) -> Positions {
  auto positions = Positions{};

  for (auto column : columns)
    positions = join({ positions, combos(rows, column) });

  return positions;
}
