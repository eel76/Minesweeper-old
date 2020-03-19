#include "player/computer.h"

#include "concealed.h"
#include "deadly.h"
#include "marked.h"
#include "move.h"
#include "move/mark.h"
#include "move/reveal.h"
#include "neighbor.h"
#include "positions.h"
#include "revealed.h"
#include "take.h"

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

  auto partition(Cells cells, Filter filter) {
    std::partition(begin(cells), end(cells), filter);
    return cells;
  }

  auto computerMove(Board board) -> Move {
    auto const concealedCells = concealed(cellsOf(board));
    if (concealedCells.empty())
      throw;

    if (auto cells = concealedCells | markMissing(board) | take (1); !cells.empty())
      return move::mark(position(cells.front()));

    return move::reveal(position(partition(concealedCells, safe(board))[0]));
  }
}}

auto minesweeper::player::computer() -> Player {
  return [](auto board) { return computerMove(board); };
}
