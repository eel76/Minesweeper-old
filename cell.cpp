#include "cell.h"

auto minesweeper::isRevealed(Cell cell) -> bool {
  return isRevealed(std::get<Threat>(cell));
}

auto minesweeper::isDeadly(Cell cell) -> bool {
  return isDeadly(std::get<Threat>(cell));
}
