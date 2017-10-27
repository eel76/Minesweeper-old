#include "computer.h"
#include "concealed.h"
#include "deadly.h"
#include "flagged.h"
#include "move.h"
#include "neighbor.h"
#include "parse.h"
#include "positions.h"
#include "revealed.h"
#include <algorithm>
#include <functional>
#include <iostream>

using namespace minesweeper;
using namespace std;

Filter threatMarkable(Board board) {
  return [board](auto cell) {
    auto const neighbors = cells(board) | neighborOf(get<Position>(cell));
    return size(neighbors | deadly()) == size(neighbors | !revealed());
  };
}

Filter threatMarked(Board board) {
  return [board](auto cell) {
    auto const neighbors = cells(board) | neighborOf(get<Position>(cell));
    return size(neighbors | deadly()) == size(neighbors | marked());
  };
}

Filter markMissing(Board board) {
  return [board](auto cell) {
    auto const hints = cells(board) | revealed() | neighborOf(get<Position>(cell));
    return any_of(begin(hints), end(hints), threatMarkable(board));
  };
}

Filter safe(Board board) {
  return [board](auto cell) {
    auto const hints = cells(board) | revealed() | neighborOf(get<Position>(cell));
    return any_of(begin(hints), end(hints), threatMarked(board));
  };
}

Move minesweeper::computerMove(Board board) {
  auto const concealedCells = cells(board) | concealed();

  for (auto cell : concealedCells | markMissing(board))
    return markAction(get<Position>(cell));

  for (auto cell : concealedCells | safe(board))
    return revealAction(get<Position>(cell));

  return revealAction(get<Position>(shuffle(concealedCells)[0]));
}

minesweeper::Player minesweeper::computerPlayer() {
  return [](auto board) { return computerMove(board); };
}
