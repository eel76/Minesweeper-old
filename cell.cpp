#include "cell.h"

auto minesweeper::position(Cell cell) -> Position {
  return cell.position;
}

auto minesweeper::threat(Cell cell) -> Threat {
  return cell.threat;
}
