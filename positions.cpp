#include "positions.h"

minesweeper::Positions minesweeper::toPositions(Cells cells) {
  auto positions = Positions{};

  for (auto cell : cells)
    positions.push_back(std::get<Position>(cell));

  return positions;
}
