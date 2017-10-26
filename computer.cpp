#include "computer.h"
#include "concealed.h"
#include "deadly.h"
#include "flagged.h"
#include "join.h"
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

bool anyOf(Cells cells, Filter test) {
  return any_of(begin(cells), end(cells), test);
}

Filter threatHidden(Board board) {
  return [=](auto cell) {
    auto neighbors = cells(board) | neighborOf(get<Position>(cell));
    return size(neighbors | deadly()) == size(neighbors | !revealed());
  };
}

bool markMissing(Board board, Position position) {
  auto hints = cells(board) | neighborOf(position) | revealed();
  return anyOf(hints, threatHidden(board));
}

Filter markMissing(Board board) {
  return [=](auto cell) { return markMissing(board, get<Position>(cell)); };
}

Filter threatMarked(Board board) {
  return [=](auto cell) {
    auto neighbors = cells(board) | neighborOf(get<Position>(cell));
    return size(neighbors | deadly()) == size(neighbors | flagged());
  };
}

Filter safe(Board board) {
  return [=](auto cell) {
    return anyOf(cells(board) | neighborOf(get<Position>(cell)) | revealed(),
                 threatMarked(board));
  };
}

Move minesweeper::computerMove(Board board) {
  auto const concealedCells = cells(board) | concealed();

  for (auto cell : concealedCells | markMissing(board))
    return mark(get<Position>(cell));

  for (auto cell : concealedCells | safe(board))
    return reveal(get<Position>(cell));

  return reveal(get<Position>(shuffle(concealedCells)[0]));
}

minesweeper::Player minesweeper::computerPlayer() {
  return [](auto board) { return computerMove(board); };
}
