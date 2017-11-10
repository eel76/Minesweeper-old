#include "combos.h"

namespace {
  template <class Container>
  Container join(std::initializer_list<Container> containerLists) {
    auto joined = Container{};

    for (auto container : containerLists)
      joined.insert(end(joined), begin(container), end(container));

    return joined;
  }
}

minesweeper::Positions minesweeper::combos(Rows rows, Column column) {
  auto positions = Positions{};

  for (auto row : rows)
    positions = join({ positions, Positions{ Position{ row, column } } });

  return positions;
}

minesweeper::Positions minesweeper::combos(Rows rows, Columns columns) {
  auto positions = Positions{};

  for (auto column : columns)
    positions = join({ positions, combos(rows, column) });

  return positions;
}
