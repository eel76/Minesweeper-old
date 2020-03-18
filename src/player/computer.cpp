#include "player/computer.h"

#include "concealed.h"
#include "deadly.h"
#include "marked.h"
#include "move.h"
#include "neighbor.h"
#include "parse.h"
#include "positions.h"
#include "revealed.h"

#include <algorithm>
#include <random>

namespace minesweeper { namespace {

  Filter threatMarkable(Board board) {
    return [board](auto cell) {
      auto const neighbors = cellsOf(board) | neighborOf(cell);
      return size(neighbors | isDeadly()) == size(neighbors | !revealed());
    };
  }

  Filter threatMarked(Board board) {
    return [board](auto cell) {
      auto const neighbors = cellsOf(board) | neighborOf(cell);
      return size(neighbors | isDeadly()) == size(neighbors | marked());
    };
  }

  Filter markMissing(Board board) {
    return [board](auto cell) {
      auto const hints = cellsOf(board) | revealed() | neighborOf(cell);
      return any_of(begin(hints), end(hints), threatMarkable(board));
    };
  }

  Filter safe(Board board) {
    return [board](auto cell) {
      auto const hints = cellsOf(board) | revealed() | neighborOf(cell);
      return any_of(begin(hints), end(hints), threatMarked(board));
    };
  }

  auto computerMove(Board board) -> Move {
    auto concealedCells = concealed(cellsOf(board));
    // FIXME: concealedCells isEmpty()

    for (auto cell : concealedCells | markMissing(board))
      return markingMove(position(cell));

    std::partition(begin(concealedCells), end(concealedCells), safe(board));
    return revealingMove(position(concealedCells[0]));
  }
}}

auto minesweeper::player::computer() -> Player {
  return computerMove;
}
