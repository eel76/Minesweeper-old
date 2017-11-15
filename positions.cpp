#include "positions.h"

auto minesweeper::toPositions(Cells cells) -> Positions {
  auto positions = Positions{};

  for (auto cell : cells)
    positions.push_back(std::get<Position>(cell));

  return positions;
}
