#include "computer.h"
#include "concealed.h"
#include "deadly.h"
#include "marked.h"
#include "move.h"
#include "neighbor.h"
#include "parse.h"
#include "positions.h"
#include "revealed.h"
#include <algorithm>

namespace minesweeper { namespace {

  Filter threatMarkable(Board board) {
    return [board](auto cell) {
      auto const neighbors = cells(board) | neighborOf(position(cell));
      return size(neighbors | isDeadly()) == size(neighbors | !revealed());
    };
  }

  Filter threatMarked(Board board) {
    return [board](auto cell) {
      auto const neighbors = cells(board) | neighborOf(position(cell));
      return size(neighbors | isDeadly()) == size(neighbors | marked());
    };
  }

  Filter markMissing(Board board) {
    return [board](auto cell) {
      auto const hints =
      cells(board) | revealed() | neighborOf(position(cell));
      return any_of(begin(hints), end(hints), threatMarkable(board));
    };
  }

  Filter safe(Board board) {
    return [board](auto cell) {
      auto const hints =
      cells(board) | revealed() | neighborOf(position(cell));
      return any_of(begin(hints), end(hints), threatMarked(board));
    };
  }
}}

auto minesweeper::computerMove(Board board) -> Move {
  auto const concealedCells = cells(board) | isConcealed();

  for (auto cell : concealedCells | markMissing(board))
    return markingMove(position(cell));

  for (auto cell : concealedCells | safe(board))
    return revealingMove(position(cell));

  return revealingMove(position(shuffled(concealedCells)[0]));
}

auto minesweeper::computerPlayer() -> Player {
  return &computerMove;
}
